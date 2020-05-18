CFLAGS = -std=c99 -Wall -Wno-cpp -Wno-unused-label -Wshadow -Wvla

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0 -fsanitize=bounds-strict
else
	CFLAGS += -O2
endif

disassembler: disassembler.c lookup_tables.h
	$(CC) -o disassembler $(CFLAGS) disassembler.c lookup_tables.h

clean:
	rm -f disassembler *.out *.o *.gch
