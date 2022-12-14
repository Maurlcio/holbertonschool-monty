#include "monty.h"

/**
 * _ischar - checks if an element of a string is a char.
 * this function was made purely to be extra cause i wanted to
 *
 * @str: string
 * @c: char to locate
 *
 * Return: 0 on success. 1 on edge case
 */

int _ischar(char *str, char c)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == c)
		{
			break;
		}
		count++;
	}
	if (str[count] == c)
		return (0);
	return (1);
}

/**
 * _strtok - emulates strtok and saves me some time
 *
 * @str: string to tokenize
 * @delim: delimiter
 *
 * Return: first token
 */

char *_strtok(char *str, char *delim)
{
	static char *l;
	int a = 0, b = 0;

	if (!str)
		str = l;

	while (str[a] != '\0')
	{
		if (_ischar(delim, str[a]) == 1 && str[a + 1] == '\0')
		{
			l = str + a + 1;
			*l = '\0';
			str += b;
			return (str);
		}
		else if (_ischar(delim, str[a]) == 1 && _ischar(delim, str[a + 1]) == 1)
			a++;
		else if (_ischar(delim, str[a]) == 1 && _ischar(delim, str[a + 1]) == 0)
		{
			l = str + a + 1;
			*l = '\0';
			l++;
			str += b;
			return (str);
		}
		else if (_ischar(delim, str[a]) == 0)
		{
			b++;
			a++;
		}
	}
	return (NULL);
}
