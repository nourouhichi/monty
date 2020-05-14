#include "monty.h"
/**
 * openf - opens the file
 * @filen: file name
 * Return: the file
 */
FILE *openf(char *filen)
{
	FILE *f;

	f = fopen(filen, "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filen);
		exit(EXIT_FAILURE);
	}
	return (f);

}
/**
 * readf - reads and looks  for the right function
 * @f: the file
 */
void readf(FILE *f)
{
	size_t n = 0;
	char *lineptr = NULL;
	int linen = 1;

	while (getline(&lineptr, &n, f) != EOF)
	{
		find_op(lineptr, linen);
		linen++;
	}

	free(lineptr);
}
