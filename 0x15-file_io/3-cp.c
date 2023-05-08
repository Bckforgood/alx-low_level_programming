#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void exit_with_error(char *message, char *arg, int code) {
    dprintf(STDERR_FILENO, message, arg);
    exit(code);
}

int main(int argc, char *argv[]) {
    int fd_from, fd_to, rd, wr;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        exit_with_error("Usage: cp file_from file_to\n", "", 97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        exit_with_error("Error: Can't read from file %s\n", argv[1], 98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_to == -1) {
        exit_with_error("Error: Can't write to %s\n", argv[2], 99);
    }

    while ((rd = read(fd_from, buffer, BUF_SIZE)) > 0) {
        wr = write(fd_to, buffer, rd);
        if (wr == -1) {
            exit_with_error("Error: Can't write to %s\n", argv[2], 99);
        }
    }

    if (rd == -1) {
        exit_with_error("Error: Can't read from file %s\n", argv[1], 98);
    }

    if (close(fd_from) == -1) {
        exit_with_error("Error: Can't close fd %d\n", fd_from, 100);
    }

    if (close(fd_to) == -1) {
        exit_with_error("Error: Can't close fd %d\n", fd_to, 100);
    }

    return 0;
}

