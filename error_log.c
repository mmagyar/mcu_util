#include "error_log.h"

Error error_log[ERROR_LOG_SIZE] ={0};
/**
 * This function requires a stack allocated struct, this will be copied to the appropriate location
 * The user does not need to dynamically allocate memory for this.
 */
void log_error_direct(Error error) {
    bool errorAlreadyLogged = false;
    for (unsigned int i = 0; i < ERROR_LOG_SIZE; i++) {
        Error* lastError = &error_log[i];
        char lastCode = lastError->error_code;
        char lastIdentifier = lastError->identifier;
        if (lastCode == error.error_code && lastIdentifier == error.identifier) {
            errorAlreadyLogged = true;
        }
    }
    if (!errorAlreadyLogged && error_count < ERROR_LOG_SIZE) {
        //Copy error from stack to a known location
        error_log[error_count].error_code = error.error_code;
        error_log[error_count].identifier= error.identifier;
    }

    error_count++;

}

void log_error(Error_codes error_code, char identifier) {
    bool errorAlreadyLogged = false;
    for (unsigned int i = 0; i < ERROR_LOG_SIZE; i++) {
        Error* last_error = &error_log[i];
        if (error_code == last_error->error_code && identifier == last_error->identifier) {
            errorAlreadyLogged = true;
        }
    }
    if (!errorAlreadyLogged && error_count < ERROR_LOG_SIZE) {
        //Copy error from stack to a known location
        error_log[error_count].error_code = error_code;
        error_log[error_count].identifier= identifier;
    }

    error_count++;
}
