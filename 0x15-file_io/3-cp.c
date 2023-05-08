#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", program_name);
    exit(97);
}

void print_error(char *message, char *filename) {
    dprintf(STDERR_FILENO, "Error: %s %s\n", message, filename);
    exit(98);
}

void print_write_error(char *filename) {
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
    exit(99);
}

void print_close_error(int fd) {
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
    exit(100);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
    }

    char *file_from = argv[1];
    char *file_to = argv[2];

    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        print_error("Can't read from file", file_from);
    }

    int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) {
        print_error("Can't write to", file_to);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            print_write_error(file_to);
        }
    }
    if (bytes_read == -1) {
        print_error("Can't read from file", file_from);
    }

    int close_from = close(fd_from);
    if (close_from == -1) {
        print_close_error(fd_from);
    }

    int close_to = close(fd_to);
    if (close_to == -1) {
        print_close_error(fd_to);
    }

    return 0;
}

