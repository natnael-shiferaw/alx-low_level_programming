#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_elf_info(int elf);

/**
* main - Entry point for ELF header information display program.
* @argc: IS The number of command-line arguments.
* @argv: An ARRAY of COMMAND-LINE argument strings.
* Return: 0 on success, 98 on error.
*/
int main(int argc, char *argv[])
{
int elf;

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

print_elf_info(elf);

if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot close file descriptor %d\n", elf);
return (98);
}

return (0);
}

/**
* print_elf_info -IS A FUNCTION THAT PRINTS INFORMATION FROM THE ELF HEADER.
* @elf: IS The FILE descriptor of the ELF file.
*/
void print_elf_info(int elf)
{
Elf64_Ehdr elf_header;
ssize_t bytes_read;

bytes_read = read(elf, &elf_header, sizeof(elf_header));
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot read from file descriptor %d\n", elf);
exit(98);
}

check_elf(elf_header.e_ident);
print_magic(elf_header.e_ident);
print_class(elf_header.e_ident);
print_data(elf_header.e_ident);
print_version(elf_header.e_ident);
print_abi(elf_header.e_ident);
print_osabi(elf_header.e_ident);
print_abi(elf_header.e_ident);
print_type(elf_header.e_type, elf_header.e_ident);
print_entry(elf_header.e_entry, elf_header.e_ident);
}

/**
* check_elf -this function Checks wheather a FILE is an ELF file or not.
* @e_ident: A POINTER to an ARRAY containing the ELF MAGIC NUMBERS.
*/
void check_elf(unsigned char *e_ident)
{
for (int index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}
