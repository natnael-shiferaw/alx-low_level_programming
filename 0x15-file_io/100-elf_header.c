#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_elf_info(Elf64_Ehdr *elf_header);

/**
* print_elf_info - A FUNCTION THAT Prints information from the ELF header.
* @elf_header: A POINTER to the ELF HEADER structure.
*/
void print_elf_info(Elf64_Ehdr *elf_header)
{
int i;

printf("Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x ", elf_header->e_ident[i]);
printf("\n");
printf("Class:                             ");
switch (elf_header->e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", elf_header->e_ident[EI_CLASS]);
break;
}
printf("Data:                              ");
switch (elf_header->e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", elf_header->e_ident[EI_DATA]);
break;
}
printf("Version:             %d (current)\n", elf_header->e_ident[EI_VERSION]);
printf("OS/ABI:                            ");
switch (elf_header->e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", elf_header->e_ident[EI_OSABI]);
break;
}
printf("ABI Version:                %d\n", elf_header->e_ident[EI_ABIVERSION]);
printf("Type:                              ");
switch (elf_header->e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", elf_header->e_type);
break;
}

printf("Entry point address:               %#lx\n", elf_header->e_entry);
}

/**
* main - Entry point for ELF HEADER information DISPLAY program.
* @argc: IS The number of COMMAND-LINE arguments.
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
