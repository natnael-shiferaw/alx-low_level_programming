#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* main - GENERATES A KEY FOR CRACKME5 DEPENDING ON USERNAME.
*
* @argc: NUMBER OF ARGUMENTS.
* @argv: ARGUMENTS PASSED.
* Return: 0 on success, 1 on error
*/

int main(int argc, char *argv[])
{
	unsigned int j, k;
	char p[7] = "      ";
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	size_t LEN, ADD;

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	LEN = strlen(argv[1]);
	p[0] = l[(LEN ^ 59) & 63];
	for (j = 0, ADD = 0; j < LEN; j++)
		ADD += argv[1][j];
	p[1] = l[(ADD ^ 79) & 63];
	for (j = 0, k = 1; j < LEN; j++)
		k *= argv[1][j];
	p[2] = l[(k ^ 85) & 63];
	for (k = argv[1][0], j = 0; j < LEN; j++)
		if ((char)k <= argv[1][j])
			k = argv[1][j];
	srand(k ^ 14);
	p[3] = l[rand() & 63];
	for (k = 0, j = 0; j < LEN; j++)
		k += argv[1][j] * argv[1][j];
	p[4] = l[(k ^ 239) & 63];
	for (k = 0, j = 0; (char)j < argv[1][0]; j++)
		k = rand();
	p[5] = l[(k ^ 229) & 63];
	printf("%s\n", p);

	return (0);
}
