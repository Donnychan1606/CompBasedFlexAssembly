#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#define ERROR_MESSAGE_QUEUE_FULL         1
#define ERROR_INVALID_MESSAGE_PRIORITY   2
#define ERROR_MESSAGE_HANDLING_FAILED    3

void error_log(int error_code, const char *error_message);

#endif