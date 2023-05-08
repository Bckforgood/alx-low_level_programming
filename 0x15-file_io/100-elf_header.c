#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

void elf_header(char* elf_filename) {
    int fd;
    Elf64_Ehdr elf_header;
    int i;

    fd = open(elf_filename, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error: Cannot open file: %s\n", elf_filename);
        exit(98);
    }

    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        fprintf(stderr, "Error: Cannot read ELF header: %s\n", elf_filename);
        exit(98);
    }

    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: Not an ELF file: %s\n", elf_filename);
        exit(98);
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header.e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d\n", elf_header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Unknown");
    printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" : elf_header.e_type == ET_DYN ? "DYN (Shared object file)" : "Unknown");
    printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header.e_entry);
    close(fd);
}

