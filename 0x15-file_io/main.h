#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
/* Constants */
#define BUFFER_SIZE 1024

/* Error codes */
#define ERR_USAGE 97
#define ERR_READ 98
#define ERR_WRITE 99
#define ERR_CLOSE 100

/* Function Prototypes */
int _putchar(char c);
int main(int argc, char *argv[]);
void print_usage_error(void);
void print_read_error(char *file_from);
void print_write_error(char *file_to);
void print_close_error(int fd);
int open_file(char *file, int flags, mode_t mode);
void close_file(int fd);
ssize_t read_file(int fd, char *buffer, size_t count);
ssize_t write_file(int fd, char *buffer, size_t count);
int cp_file(char *file_from, char *file_to);

#endif /* MAIN_H */

