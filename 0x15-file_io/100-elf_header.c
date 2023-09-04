#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_elf_info(Elf64_Ehdr *elf_header);

/**
* main - Entry point for ELF HEADER information display program.
* @argc: IS THE NUMBER of COMMAND-LINE arguments.
* @argv: IS An ARRAY of COMMAND-LINE argument strings.
* Return: 0 on success, 98 on error.
*/
int main(int argc, char *argv[])
{
int elf;
Elf64_Ehdr elf_header;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
return (98);
}

elf = open(argv[1], O_RDONLY);
if (elf == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", argv[1]);
return (98);
}

if (read(elf, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
{
dprintf(STDERR_FILENO, "Error: Cannot read ELF header\n");
close(elf);
return (98);
}

print_elf_info(&elf_header);

if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot close file descriptor %d\n", elf);
return (98);
}

return (0);
}
