#ifndef MIDI_MIDI_ENUMS_H_
#define MIDI_MIDI_ENUMS_H_

typedef enum {
    NOTE_OFF = 0x80,
    NOTE_ON = 0x90,
    POLY_AFTERTOUCH = 0xA0,
    MIDI_CC = 0xB0,
    PROGRAM_CHANGE = 0xC0,
    CHANNEL_AFTERTOUCH = 0xD0,
    PITCH_WHEEL = 0xE0,
    SYSTEM_EXCLUSIVE = 0xF0
/**0XFx is reserved for system exclusive messages,
 the last 4 bit does not mean the channel there **/
} Midi_message_type;

typedef enum {
    Start = 1,
    //This may mean that the buffer is full.
    In_progress = 2,
    //End submits remaining data when buffer used,
    //and contains no data when there is no buffer
    End_sys_ex = 3,

} SysExStatus;

typedef enum {
    note_on_event = 1,
    note_off_event = 2,
    aftertouch_event = 3,
} Note_event_type;

typedef enum {
    CH00 = 0,
    CH01 = 1,
    CH02 = 2,
    CH03 = 3,
    CH04 = 4,
    CH05 = 5,
    CH06 = 6,
    CH07 = 7,
    CH08 = 8,
    CH09 = 9,
    CH10 = 10,
    CH11 = 11,
    CH12 = 12,
    CH13 = 13,
    CH14 = 14,
    CH15 = 15

} Midi_channel;

typedef enum {
    C_1 = 0,
    Cs_1 = 1,
    D_1 = 2,
    Ds_1 = 3,
    E_1 = 4,
    F_1 = 5,
    Fs_1 = 6,
    G_1 = 7,
    Gs_1 = 8,
    A_1 = 9,
    As_1 = 10,
    B_1 = 11,
    C0 = 12,
    Cs0 = 13,
    D0 = 14,
    Ds0 = 15,
    E0 = 16,
    F0 = 17,
    Fs0 = 18,
    G0 = 19,
    Gs0 = 20,
    A0 = 21,
    As0 = 22,
    B0 = 23,
    C1 = 24,
    Cs1 = 25,
    D1 = 26,
    Ds1 = 27,
    E1 = 28,
    F1 = 29,
    Fs1 = 30,
    G1 = 31,
    Gs1 = 32,
    A1 = 33,
    As1 = 34,
    B1 = 35,
    C2 = 36,
    Cs2 = 37,
    D2 = 38,
    Ds2 = 39,
    E2 = 40,
    F2 = 41,
    Fs2 = 42,
    G2 = 43,
    Gs2 = 44,
    A2 = 45,
    As2 = 46,
    B2 = 47,
    C3 = 48,
    Cs3 = 49,
    D3 = 50,
    Ds3 = 51,
    E3 = 52,
    F3 = 53,
    Fs3 = 54,
    G3 = 55,
    Gs3 = 56,
    A3 = 57,
    As3 = 58,
    B3 = 59,
    C4 = 60,
    Cs4 = 61,
    D4 = 62,
    Ds4 = 63,
    E4 = 64,
    F4 = 65,
    Fs4 = 66,
    G4 = 67,
    Gs4 = 68,
    A4 = 69,
    As4 = 70,
    B4 = 71,
    C5 = 72,
    Cs5 = 73,
    D5 = 74,
    Ds5 = 75,
    E5 = 76,
    F5 = 77,
    Fs5 = 78,
    G5 = 79,
    Gs5 = 80,
    A5 = 81,
    As5 = 82,
    B5 = 83,
    C6 = 84,
    Cs6 = 85,
    D6 = 86,
    Ds6 = 87,
    E6 = 88,
    F6 = 89,
    Fs6 = 90,
    G6 = 91,
    Gs6 = 92,
    A6 = 93,
    As6 = 94,
    B6 = 95,
    C7 = 96,
    Cs7 = 97,
    D7 = 98,
    Ds7 = 99,
    E7 = 100,
    F7 = 101,
    Fs7 = 102,
    G7 = 103,
    Gs7 = 104,
    A7 = 105,
    As7 = 106,
    B7 = 107,
    C8 = 108,
    Cs8 = 109,
    D8 = 110,
    Ds8 = 111,
    E8 = 112,
    F8 = 113,
    Fs8 = 114,
    G8 = 115,
    Gs8 = 116,
    A8 = 117,
    As8 = 118,
    B8 = 119,
    C9 = 120,
    Cs9 = 121,
    D9 = 122,
    Ds9 = 123,
    E9 = 124,
    F9 = 125,
    Fs9 = 126,
    G9 = 127
}
Midi_note;
typedef enum {
    CC_CH_000 = 0,
    CC_CH_001 = 1,
    CC_CH_002 = 2,
    CC_CH_003 = 3,
    CC_CH_004 = 4,
    CC_CH_005 = 5,
    CC_CH_006 = 6,
    CC_CH_007 = 7,
    CC_CH_008 = 8,
    CC_CH_009 = 9,
    CC_CH_010 = 10,
    CC_CH_011 = 11,
    CC_CH_012 = 12,
    CC_CH_013 = 13,
    CC_CH_014 = 14,
    CC_CH_015 = 15,
    CC_CH_016 = 16,
    CC_CH_017 = 17,
    CC_CH_018 = 18,
    CC_CH_019 = 19,
    CC_CH_020 = 20,
    CC_CH_021 = 21,
    CC_CH_022 = 22,
    CC_CH_023 = 23,
    CC_CH_024 = 24,
    CC_CH_025 = 25,
    CC_CH_026 = 26,
    CC_CH_027 = 27,
    CC_CH_028 = 28,
    CC_CH_029 = 29,
    CC_CH_030 = 30,
    CC_CH_031 = 31,
    CC_CH_032 = 32,
    CC_CH_033 = 33,
    CC_CH_034 = 34,
    CC_CH_035 = 35,
    CC_CH_036 = 36,
    CC_CH_037 = 37,
    CC_CH_038 = 38,
    CC_CH_039 = 39,
    CC_CH_040 = 40,
    CC_CH_041 = 41,
    CC_CH_042 = 42,
    CC_CH_043 = 43,
    CC_CH_044 = 44,
    CC_CH_045 = 45,
    CC_CH_046 = 46,
    CC_CH_047 = 47,
    CC_CH_048 = 48,
    CC_CH_049 = 49,
    CC_CH_050 = 50,
    CC_CH_051 = 51,
    CC_CH_052 = 52,
    CC_CH_053 = 53,
    CC_CH_054 = 54,
    CC_CH_055 = 55,
    CC_CH_056 = 56,
    CC_CH_057 = 57,
    CC_CH_058 = 58,
    CC_CH_059 = 59,
    CC_CH_060 = 60,
    CC_CH_061 = 61,
    CC_CH_062 = 62,
    CC_CH_063 = 63,
    CC_CH_064 = 64,
    CC_CH_065 = 65,
    CC_CH_066 = 66,
    CC_CH_067 = 67,
    CC_CH_068 = 68,
    CC_CH_069 = 69,
    CC_CH_070 = 70,
    CC_CH_071 = 71,
    CC_CH_072 = 72,
    CC_CH_073 = 73,
    CC_CH_074 = 74,
    CC_CH_075 = 75,
    CC_CH_076 = 76,
    CC_CH_077 = 77,
    CC_CH_078 = 78,
    CC_CH_079 = 79,
    CC_CH_080 = 80,
    CC_CH_081 = 81,
    CC_CH_082 = 82,
    CC_CH_083 = 83,
    CC_CH_084 = 84,
    CC_CH_085 = 85,
    CC_CH_086 = 86,
    CC_CH_087 = 87,
    CC_CH_088 = 88,
    CC_CH_089 = 89,
    CC_CH_090 = 90,
    CC_CH_091 = 91,
    CC_CH_092 = 92,
    CC_CH_093 = 93,
    CC_CH_094 = 94,
    CC_CH_095 = 95,
    CC_CH_096 = 96,
    CC_CH_097 = 97,
    CC_CH_098 = 98,
    CC_CH_099 = 99,
    CC_CH_100 = 100,
    CC_CH_101 = 101,
    CC_CH_102 = 102,
    CC_CH_103 = 103,
    CC_CH_104 = 104,
    CC_CH_105 = 105,
    CC_CH_106 = 106,
    CC_CH_107 = 107,
    CC_CH_108 = 108,
    CC_CH_109 = 109,
    CC_CH_110 = 110,
    CC_CH_111 = 111,
    CC_CH_112 = 112,
    CC_CH_113 = 113,
    CC_CH_114 = 114,
    CC_CH_115 = 115,
    CC_CH_116 = 116,
    CC_CH_117 = 117,
    CC_CH_118 = 118,
    CC_CH_119 = 119,
    CC_CH_120 = 120,
    CC_CH_121 = 121,
    CC_CH_122 = 122,
    CC_CH_123 = 123,
    CC_CH_124 = 124,
    CC_CH_125 = 125,
    CC_CH_126 = 126,
    CC_CH_127 = 127
} Midi_cc_number;

typedef enum {
    READY = 0,
    STATUS_RECEIVED = 1, /** This means we have a status byte set up **/
    DATA_1 = 10,
    DATA_2 = 20
} RECEIVE_STATUS;

// misc
#define MIDI_SYSTEM_COMMON      0xF0
#define MIDI_SYSEX              0xF0
#define MIDI_SYSTEM_REAL_TIME   0xF8
#define MIDI_CHANNEL_MASK       0x0F

// controllers
#define MIDI_BANK_SELECT                0
#define MIDI_MODULATION_WHEEL           1
#define MIDI_BREATH_CONTROLLER          2
#define MIDI_FOOT_PEDAL                 4
#define MIDI_PORTAMENTO_TIME            5
#define MIDI_DATA_ENTRY                 6
#define MIDI_VOLUME                     7
#define MIDI_BALANCE                    8
#define MIDI_PAN_POSITION               10
#define MIDI_EXPRESSION                 11
#define MIDI_EFFECT_CONTROL_1           12
#define MIDI_EFFECT_CONTROL_2           13
#define MIDI_GENERAL_PURPOSE_SLIDER_1   16
#define MIDI_GENERAL_PURPOSE_SLIDER_2   17
#define MIDI_GENERAL_PURPOSE_SLIDER_3   18
#define MIDI_GENERAL_PURPOSE_SLIDER_4   19
#define MIDI_BANK_SELECT_FINE           32
#define MIDI_MODULATION_WHEEL_FINE      33
#define MIDI_BREATH_CONTROLLER_FINE     34
#define MIDI_FOOT_PEDAL_FINE            36
#define MIDI_PORTAMENTO_TIME_FINE       37
#define MIDI_DATA_ENTRY_FINE            38
#define MIDI_VOLUME_FINE                39
#define MIDI_BALANCE_FINE               40
#define MIDI_PAN_POSITION_FINE          42
#define MIDI_EXPRESSION_FINE            43
#define MIDI_EFFECT_CONTROL_1_FINE      44
#define MIDI_EFFECT_CONTROL_2_FINE      45
#define MIDI_HOLD_PEDAL                 64
#define MIDI_PORTAMENTO                 65
#define MIDI_SUSTENUTO_PEDAL            66
#define MIDI_SOFT_PEDAL                 67
#define MIDI_LEGATO_PEDAL               68
#define MIDI_HOLD_2_PEDAL               69
#define MIDI_SOUND_VARIATION            70
#define MIDI_SOUND_TIMBRE               71
#define MIDI_SOUND_RELEASE_TIME         72
#define MIDI_SOUND_ATTACK_TIME          73
#define MIDI_SOUND_BRIGHTNESS           74
#define MIDI_SOUND_CONTROL_6            75
#define MIDI_SOUND_CONTROL_7            76
#define MIDI_SOUND_CONTROL_8            77
#define MIDI_SOUND_CONTROL_9            78
#define MIDI_SOUND_CONTROL_10           79
#define MIDI_GENERAL_PURPOSE_BUTTON_1   80
#define MIDI_GENERAL_PURPOSE_BUTTON_2   81
#define MIDI_GENERAL_PURPOSE_BUTTON_3   82
#define MIDI_GENERAL_PURPOSE_BUTTON_4   83
#define MIDI_EFFECTS_LEVEL              91
#define MIDI_TREMULO_LEVEL              92
#define MIDI_CHORUS_LEVEL               93
#define MIDI_CELESTE_LEVEL              94
#define MIDI_PHASER_LEVEL               95
#define MIDI_DATA_BUTTON_INCREMENT      96
#define MIDI_DATA_BUTTON_DECREMENT      97
#define MIDI_NON_REGISTERED_PARAMETER   98
#define MIDI_NON_REGISTERED_PARAMETER_FINE  99
#define MIDI_REGISTERED_PARAMETER       100
#define MIDI_REGISTERED_PARAMETER_FINE  101
#define MIDI_ALL_SOUND_OFF              120
#define MIDI_ALL_CONTROLLERS_OFF        121
#define MIDI_LOCAL_KEYBOARD             122
#define MIDI_ALL_NOTES_OFF              123
#define MIDI_OMNI_MODE_OFF              124
#define MIDI_OMNI_MODE_ON               125
#define MIDI_MONO_OPERATION             126
#define MIDI_POLY_OPERATION             127

#endif /* MIDI_MIDI_ENUMS_H_ */
