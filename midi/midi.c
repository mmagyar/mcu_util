#include <midi/midi.h>
#include <msp430.h>
#include <util.h>
#include <util/system_defs.h>


def_Circular_buffer(midiRXBuffer, MIDI_BUFFER_SIZE, 'r');
def_Circular_buffer(midiTXBuffer, MIDI_BUFFER_SIZE, 't');

#ifdef bufferSysEx
def_Circular_buffer(sys_ex_buffer, MIDI_BUFFER_SIZE, 's');
#endif

void default_cc_change_handler(Midi_channel c, Midi_cc_number n, Midi_cc_value v) {
    return; //Do nothing by default
}

void default_note_event_handler(Midi_channel channel, Midi_note note, Note_event_type type, uint8_t value) {
    return; //Do nothing by default
}

void default_program_change_handler(Midi_channel channel, uint8_t value) {
    return; //Do nothing by default
}

void default_pitch_wheel_handler(Midi_channel channel, uint16_t value) {
    return; //Do nothing by default
}

void default_channel_pressure_handler(Midi_channel channel, uint8_t value) {
    return; // Do nothing by default
}

void send_cc(Midi_channel channel, Midi_cc_number cc, uint8_t value){
    add_to_buffer(&midiTXBuffer, (MIDI_CC | channel));
    add_to_buffer(&midiTXBuffer, (uint8_t)cc &~ 0x80);
    add_to_buffer(&midiTXBuffer, value &~ 0x80 );

    IFG2 |= UCA0TXIFG;
    IE2 |= UCA0TXIE;
//    UCA0TXBUF = 0;
}

#ifdef bufferSysEx
void default_sys_ex_buffer_handler(SysExStatus status, Circular_buffer * value) {
    return; // Do nothing by default
}
#else
void default_sys_ex_byte_handler(SysExStatus status, uint8_t value) {
    return; // Do nothing by default
}
#endif

Midi_note_event_cb note_event_callback = default_note_event_handler;
Midi_cc_change_cb cc_change_callback = default_cc_change_handler;
Midi_program_change_cb program_change_callback = default_program_change_handler;
Midi_pitch_wheel_cb pitch_wheel_callback = default_pitch_wheel_handler;
Midi_channel_pressure_cb channel_pressure_callback = default_channel_pressure_handler;

#ifdef bufferSysEx
Midi_sys_ex_buffer_cb sys_ex_buffer_callback = default_sys_ex_buffer_handler;
#else
Midi_sys_ex_byte_cb sys_ex_byte_callback = default_sys_ex_byte_handler;
#endif

Current_message current = { READY, CH00, C4,  CC_CH_000, 0,  NOTE_OFF, false};
#define RECEIVE_2_BYTES(byte1,byte2)    \
    if (current.receive_status == MESSAGE_TYPE) { \
        current.receive_status = DATA_1; \
        byte1 \
    } else if (current.receive_status == DATA_1) { \
        current.receive_status = DATA_2; \
        byte2 \
        current.receive_status = READY; \
    } else { logError(EC_MIDI_INVALID_STATE , 'r'); }

void processIncomingMessages() {
    Buffer_read_result bufferResult;
    pop_from_buffer(&midiRXBuffer,&bufferResult);
    if (!bufferResult.readSuccess) {
        return;
    }

    char midi_cd = bufferResult.data;

    //High byte set, means new message
    //System messages
    if((midi_cd & 0xF0) == 0xF0) {
        switch(midi_cd) {
            //System Exclusive, n byte
            case 0xF0:
                current.message_type = SYSTEM_EXCLUSIVE;
                break;
            //System Common MIDI Time Code Quarter Frame. 2 bytes.
            case 0xF1:

                break;
            //System Common Song Position Pointer. 2 bytes.
            case 0xF2:
                break;
            //System Common Song Select. 2 bytes.
            case 0xF3:
                break;
            //Undefined (reserved)
            case 0xF4:
                break;
           //Undefined (reserved)
            case 0xF5:
                break;
            //System Common Tune Request, all analog synthesizers should tune their oscillators.
            case 0xF6:
                break;
            //End of Exclusive. Used to terminate a System Exclusive dump.
            case 0xF7:
                #ifdef bufferSysEx
                    sys_ex_buffer_callback(End_sys_ex, &sys_ex_buffer);
                #else
                    sys_ex_byte_callback(End_sys_ex, 0);
                #endif
                break;
            //System real-time messages
            //Timing Clock. Sent 24 times per quarter note when synchronization is required
            case 0xF8:
                break;
            // Undefined (Reserved)
            case 0xF9:
                break;
            // Start the current sequence playing. (This message will be followed with Timing Clocks).
            case 0xFA:
                break;
             // Continue at the point the sequence was Stopped.
            case 0xFB:
                break;
            // Stop the current sequence.
            case 0xFC:
                break;
            // Undefined (Reserved)
            case 0xFD:
                break;
            /**
             * Active Sensing
             * This message is intended to be sent repeatedly to tell the receiver that a connection is alive.
             * Use of this message is optional. When initially received,
             * the receiver will expect to receive another Active Sensing message each 300ms (max),
             * and if it does not then it will assume that the connection has been terminated.
             *  At termination, the receiver will turn off all voices and return to normal
             *  (non- active sensing) operation.
             */
            case 0xFE:
                break;
            //Reset all the receivers in the system to power up status. This should be used sparingly
            //Preferably under manual control. It should not be sent on power-up.
            case 0xFF:
                break;

        };

    //Normal midi message beginning, containing message type and channel.
    } else if (midi_cd & 0x80) {

        if (current.receive_status != READY) {
            logError(EC_MIDI_UNFINISHED_MESSAGE, 'r');
            // return; // may need to rethink this error handling
        }

        //Midi channel was not assigned in the ignore group,
        //probably does not have any significance,
        //but leaving this comment if it does
        current.channel = (Midi_channel) (midi_cd & 0x0F);
        current.receive_status = MESSAGE_TYPE;

        //0xFE indicates that an input device is connected
        if (midi_cd == 0xFE) {
            //midi_running++;
        } else {
            current.message_type = (Midi_message_type) (midi_cd & 0xF0);
        }

    } else {
        #ifdef bufferSysEx
            bool sys_ex_res = false;
        #endif
        //Normal messages
        switch (current.message_type) {
            case NOTE_ON: //Note on with velocity 0 is note off
                RECEIVE_2_BYTES({current.note = (Midi_note ) midi_cd;},
                    {note_event_callback(current.channel, current.note,
                        midi_cd ? note_on_event : note_off_event, midi_cd);});
                break;
            case NOTE_OFF:
                RECEIVE_2_BYTES({current.note = (Midi_note ) midi_cd;},
                    {note_event_callback(current.channel, current.note, note_off_event, midi_cd);});
                break;
            case POLY_AFTERTOUCH:
                RECEIVE_2_BYTES({current.note = (Midi_note ) midi_cd;},
                    {note_event_callback(current.channel, current.note, aftertouch_event, midi_cd);});
                break;
            case MIDI_CC:
                RECEIVE_2_BYTES({current.cc_number = (Midi_cc_number) midi_cd;},
                    {cc_change_callback(current.channel, current.cc_number, midi_cd);});
                break;
            case PROGRAM_CHANGE:
                if (current.receive_status == MESSAGE_TYPE) {
                    program_change_callback(current.channel,midi_cd);
                    current.receive_status = READY;
                } else {logError(EC_MIDI_INVALID_STATE , 'p');}
                break;
            case CHANNEL_AFTERTOUCH:
                if (current.receive_status == MESSAGE_TYPE) {
                    channel_pressure_callback(current.channel,midi_cd);
                    current.receive_status = READY;
                } else {logError(EC_MIDI_INVALID_STATE , 'a');}
                break;
            case PITCH_WHEEL:
                RECEIVE_2_BYTES({current.pitchwheel=  midi_cd;},
                    {pitch_wheel_callback(current.channel,current.pitchwheel | midi_cd << 7);});
                break;
            case SYSTEM_EXCLUSIVE:
                #ifdef bufferSysEx
                sys_ex_res = add_to_buffer_if_not_full(&sys_ex_buffer, midi_cd);
                if (!sys_ex_res) {
                    //Send buffer to callback, since it's full
                    sys_ex_buffer_callback(In_progress, &sys_ex_buffer);
                    //Reset the buffer
                    reset(&sys_ex_buffer);
                }
                //Add new data to buffer
                add_to_buffer(&sys_ex_buffer, midi_cd);
                //TODO maybe convert 7 bits messages to 8 bits

                #else
                sys_ex_byte_callback(In_progress, midi_cd);
#endif
                break;
            default:
                logError(EC_MIDI_EMPTY_MESSAGE_TYPE, 'r');
                break;
        }
    }

}