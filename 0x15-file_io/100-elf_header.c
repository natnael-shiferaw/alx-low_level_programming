#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void close_elf(int elf);
void check_elf(unsigned char *e_ident);

/**
* check_elf - Checks if a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*/
void check_elf(unsigned char *e_ident)
{
int INDEX;

for (INDEX = 0; INDEX < 4; INDEX++)
{
if (e_ident[INDEX] != 127 &&
e_ident[INDEX] != 'E' &&
e_ident[INDEX] != 'L' &&
e_ident[INDEX] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* print_magic - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*/
void print_magic(unsigned char *e_ident)
{
int INDEX;

printf(" Magic: ");

for (INDEX = 0; INDEX < EI_NIDENT; INDEX++)
{
printf("%02x", e_ident[INDEX]);

if (INDEX == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
* print_class -A FUNCTION that PRINTS class of an ELF HEADER.
* @e_ident: A POINTER to an ARRAY containing the ELF class.
*/
void print_class(unsigned char *e_ident)
{
printf(" Class: ");

switch (e_ident[EI_CLASS])
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
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* print_data - Prints the data of an ELF header.
* @e_ident: A POINTER to an ARRAY THAT CONTAINS the ELF CLASS.
*/
void print_data(unsigned char *e_ident)
{
printf(" Data: ");

switch (e_ident[EI_DATA])
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
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* print_version -A VOID function that PRINTS the version of an ELF HEADER.
* @e_ident: A POINTER to an ARRAY containing the ELF version.
*/
void print_version(unsigned char *e_ident)
{
printf(" Version: %d",
e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
* print_osabi - A FUNCTION THAT Prints the OS/ABI of an ELF HEADER.
* @e_ident: A POINTER to an ARRAY containing the ELF version.
*/
void print_osabi(unsigned char *e_ident)
{
printf(" OS/ABI: ");

switch (e_ident[EI_OSABI])
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
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
* print_abi -A VOID FUNCTION that PRINTS the ABI version of an ELF HEADER.
* @e_ident: A POINTER to an ARRAY THAT CONTAINS the ELF ABI version.
*/
void print_abi(unsigned char *e_ident)
{
printf(" ABI Version: %d\n",
e_ident[EI_ABIVERSION]);
}

/**
* print_type - Prints the type of an ELF header.
* @e_type: REPRESENTS The ELF TYPE.
* @e_ident: A POINTER to an ARRAY that contains the ELF CLASS.
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf(" Type: ");
switch (e_type)
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
printf("<unknown: %x>\n", e_type);
}
}

/**
* print_entry - a function that Prints the entry point of an ELF HEADER.
* @e_entry: Is The address of the ELF ENTRY point.
* @e_ident: iS a POINTER to an ARRAY containing the ELF CLASS.
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf(" Entry point address: ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
}
