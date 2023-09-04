#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - Allocates memory for a buffer to read and write data.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		perror("Error: Unable to allocate buffer");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int result = close(fd);

	if (result == -1)
	{
		perror("Error: Unable to close file descriptor");
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the program's arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect, the program exits with code 97.
 * If the source file cannot be opened or read, the program exits with code 98.
 * If the destination file cannot be created or written to, the program exits with code 99.
 * If there are issues closing files, the program exits with code 100.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if(argc != 3)
	{
		fprintf(stderr, "Usage: cp source_file destination_file\n");
		exit(EXIT_FAILURE);
	}

	buffer = create_buffer();

	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
	{
		perror("Error: Unable to open source file");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (dest_fd == -1)
	{
		perror("Error: Unable to open destination file");
		free(buffer);
		close_file(source_fd);
		exit(EXIT_FAILURE);
	}

	while ((bytes_read = read(source_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);

		if (bytes_written == -1)
		{
			perror("Error: Unable to write to destination file");
			free(buffer);
			close_file(source_fd);
			close_file(dest_fd);
			exit(EXIT_FAILURE);
		}
	}

	free(buffer);
	close_file(source_fd);
	close_file(dest_fd);

	return EXIT_SUCCESS;
}
