#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_and_print_text - Read text from a file and print it to STDOUT.
 * @filename: The name of the text file to be read.
 * @max_letters: The maximum number of letters to be read and printed.
 * Return: The actual number of bytes read and printed on success,
 *         or -1 when the function fails or if the filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t max_letters)
{
	ssize_t bytes_read;

	char *buffer;
	int file_descriptor;
	ssize_t total_bytes_read = 0;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (-1);

	buffer = malloc(max_letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (-1);
	}


	while ((bytes_read = read(file_descriptor, buffer, max_letters)) > 0)
	{
		ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			free(buffer);
			close(file_descriptor);
			return (-1);
		}
		total_bytes_read += bytes_read;
	}

	free(buffer);
	close(file_descriptor);

	return (total_bytes_read);
}
