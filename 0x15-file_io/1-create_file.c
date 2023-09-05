#include "main.h"

/**
 * create_or_truncate_file - Creates a new file or truncates an existing one.
 * @filename: A pointer to the name of the file to be created or truncated.
 * @text_content: A pointer to the string to write to the file (can be NULL).
 *
 * Return: On success, 1. On failure, -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; len++)
			;
	}

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (len > 0)
	{
		w = write(fd, text_content, len);

		if (w == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
