
#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define CP_USAGE_ERROR 97
#define CP_READ_ERROR 98
#define CP_WRITE_ERROR 99
#define CP_CLOSE_ERROR 100

int check_arg_count(int argc);
int copy_file(const char *file_from, const char *file_to);
int create_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);
int fd_from, fd_to, rd, wr;
char buffer[BUFSIZ];
void error(char *message);
int open_file(const char *file, int mode, int exit_code);
int create_file(const char *filename, char *text_content);
void exit_with_error(char *message, char *arg, int code);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
