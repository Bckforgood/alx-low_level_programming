#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, or appropriate error code
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, bytes_read, bytes_written;
    char buf[1024];

    /* check for correct number of arguments */
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        return (EXIT_FAILURE);
    }

    /* open file_from for reading */
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    /* open file_to for writing, truncating if it already exists */
    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close(fd_from);
        return (EXIT_FAILURE);
    }

    /* copy contents of file_from to file_to */
    while ((bytes_read = read(fd_from, buf, 1024)) > 0)
    {
        bytes_written = write(fd_to, buf, bytes_read);
        if (bytes_written != bytes_read)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
            return (EXIT_FAILURE);
        }
    }

    /* check for read error */
    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd_from);
        close(fd_to);
        return (EXIT_FAILURE);
    }

    /* close file descriptors */
    if (close(fd_from) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        return (EXIT_FAILURE);
    }
    if (close(fd_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

