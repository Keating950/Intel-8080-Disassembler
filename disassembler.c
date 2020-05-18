#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include "lookup_tables.h"

#define DIE(...)                                                               \
	do {                                                                       \
		fprintf(stderr, __VA_ARGS__);                                          \
		exit(EXIT_FAILURE);                                                    \
	} while (0)

#define BYTE(OFFSET) rom[pc+OFFSET]

size_t map_file(const char *path);
void disassemble(size_t rom_size);

uint8_t *rom = NULL;

int main(int argc, char **argv)
{
	size_t rom_size;
	if (argc < 2)
		DIE("%s [path to rom]\n", argv[0]);
	rom_size = map_file(argv[1]);
	disassemble(rom_size);
	exit(EXIT_SUCCESS);
}

size_t map_file(const char* path)
{
	FILE *f;
	size_t rom_size;
	int fd;

	f = fopen(path, "rb");
	if (!f)
		DIE("Failed to open %s\n", path);
	if (fseek(f, 0, SEEK_END))
		DIE("Error reading %s\n", path);
	rom_size = (size_t)ftell(f);
	fclose(f);

	fd = open(path, O_RDONLY);
	if (!fd)
		DIE("Failed to acquire file descriptor for %s\n", path);
	rom = (uint8_t *)mmap(NULL, rom_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (!rom)
		DIE("Failed to memory-map %s\n", path);
	return rom_size;
}

void disassemble(size_t rom_size)
{
	puts("\e[1mpc\tinstruction\tbytes\e[0m");
	int pc = 0;
	while (pc < rom_size) {
		printf("%04X\t%-8s\t", pc, op_mnemonics[BYTE(0)]);
		switch (op_sizes[rom[pc]]) {
		case 3:
			printf("%02X\t%02X %02X\n", BYTE(0), BYTE(2), BYTE(1));
			break;
		case 2:
			printf("%02X\t%02X --\n", BYTE(0), BYTE(1));
			break;
		case 1:
			printf("%02X\t-----\n", BYTE(0));
		default:
			break;
		}
		pc += op_sizes[rom[pc]];
	}
}
