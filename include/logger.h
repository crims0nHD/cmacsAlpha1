#ifndef __LOGGER_H_
#define __LOGGER_H_

#define NULL 0

extern int log_init(char *filepath); // filepath: nullptr if no file path
extern int log_exit();
extern int log_echo();

extern int logerror(char *error);
extern int logwarning(char *warning);
extern int logmessage(char *message);

#endif // __LOGGER_H_
