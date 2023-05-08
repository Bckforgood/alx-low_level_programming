#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void error(char *message) {
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int fd_from, fd_to, read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        error("Usage: cp file_from file_to");
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        error("Can't read from file");
    }

    fd_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
    if (fd_to == -1) {
        error("Can't write to file");
    }

    while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes) {
            error("Can't write to file");
        }
    }

    if (read_bytes == -1) {
        error("Can't read from file");
    }

    if (close(fd_from) == -1) {
        error("Can't close file descriptor");
    }

    if (close(fd_to) == -1) {
        error("Can't close file descriptor");
    }

    return 0;
}

