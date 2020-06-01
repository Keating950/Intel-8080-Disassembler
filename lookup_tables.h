#ifndef __LOOKUP_TABLES_H__
#define __LOOKUP_TABLES_H__

// clang-format off
const char *const op_mnemonics[0x100] = {
//    0          1          2          3          4          5           6          7          8          9          A          B          C          D          E          F
/*0*/ "NOP",     "LXI B",   "STAX B",  "INX B",   "INR B",   "DCR B",    "MVI B",   "RLC",     "ILLEGAL", "DAD B",   "LDAX B",  "DCX B",   "INR C",   "DCR C",   "MVI C",   "RRC",
/*1*/ "ILLEGAL", "LXI D",   "STAX D",  "INX D",   "INR D",   "DCR D",    "MVI D",   "RAL",     "ILLEGAL", "DAD D",   "LDAX D",  "DCX D",   "INR E",   "DCR E",   "MVI E",   "RAR",
/*2*/ "ILLEGAL", "LXI H",   "SHLD",    "INX H",   "INR H",   "DCR H",    "MVI H",   "DAA",     "ILLEGAL", "DAD H",   "LHLD",    "DCX H",   "INR L",   "DCR L",   "MVI L",   "CMA",
/*3*/ "ILLEGAL", "LXI SP",  "STA",     "INX SP",  "INR M",   "DCR M",    "MVI M",   "STC",     "ILLEGAL", "DAD SP",  "LDA",     "DCX SP",  "INR A",   "DCR A",   "MVI A",   "CMC",
/*4*/ "MOV B,B", "MOV B,C", "MOV B,D", "MOV B,E", "MOV B,H", "MOV B,L",  "MOV B,M", "MOV B,A", "MOV C,B", "MOV C,C", "MOV C,D", "MOV C,E", "MOV C,H", "MOV C,L", "MOV C,M", "MOV C,A",
/*5*/ "MOV D,B", "MOV D,C", "MOV D,D", "MOV D,E", "MOV D,H", "MOV D,L",  "MOV D,M", "MOV D,A", "MOV E,B", "MOV E,C", "MOV E,D", "MOV E,E", "MOV E,H", "MOV E,L", "MOV E,M", "MOV E,A",
/*6*/ "MOV H,B", "MOV H,C", "MOV H,D", "MOV H,E", "MOV H,H", "MOV H,L",  "MOV H,M", "MOV H,A", "MOV L,B", "MOV L,C", "MOV L,D", "MOV L,E", "MOV L,H", "MOV L,L", "MOV L,M", "MOV L,A",
/*7*/ "MOV M,B", "MOV M,C", "MOV M,D", "MOV M,E", "MOV M,H", "MOV M,L",  "HLT",     "MOV M,A", "MOV A,B", "MOV A,C", "MOV A,D", "MOV A,E", "MOV A,H", "MOV A,L", "MOV A,M", "MOV A,A",
/*8*/ "ADD B",   "ADD C",   "ADD D",   "ADD E",   "ADD H",   "ADD L",    "ADD M",   "ADD A",   "ADC B",   "ADC C",   "ADC D",   "ADC E",   "ADC H",   "ADC L",   "ADC M",   "ADC A",
/*9*/ "SUB B",   "SUB C",   "SUB D",   "SUB E",   "SUB H",   "SUB L",    "SUB M",   "SBB A",   "SBB B",   "SBB C",   "SBB D",   "SBB E",   "SBB H",   "SBB L",   "SBB M",   "SBB A",
/*A*/ "ANA B",   "ANA C",   "ANA D",   "ANA E",   "ANA H",   "ANA L",    "ANA M",   "ANA A",   "XRA B",   "XRA C",   "XRA D",   "XRA E",   "XRA H",   "XRA L",   "XRA M",   "XRA A",
/*B*/ "ORA B",   "ORA C",   "ORA D",   "ORA E",   "ORA H",   "ORA L",    "ORA M",   "ORA A",   "CMP B",   "CMP C",   "CMP D",   "CMP E",   "CMP H",   "CMP L",   "CMP M",   "CMP A",
/*C*/ "RNZ",     "POP B",   "JNZ",     "JMP",     "CNZ",     "PUSH B",   "ADI",     "RST 0",   "RZ",      "RET",     "JZ",      "ILLEGAL", "CZ",      "CALL",    "ACI",     "RST 1",
/*D*/ "RNC",     "POP D",   "JNC",     "OUT",     "CNC",     "PUSH D",   "SUI",     "RST 2",   "RC",      "ILLEGAL", "JC",      "IN",      "CC",      "ILLEGAL", "SBI",     "RST 3",
/*E*/ "RPO",     "POP H",   "JPO",     "XTHL",    "CPO",     "PUSH H",   "ANI",     "RST 4",   "RPE",     "PCHL",    "JPE",     "XCHG",    "CPE",     "ILLEGAL", "XRI",     "RST 5",
/*F*/ "RP",      "POPPSW",  "JP",      "DI",      "CP",      "PUSH PSW", "ORI",     "RST 6",   "RM",      "SPHL",    "JM",      "EI",      "CM",      "ILLEGAL", "CPI",     "RST 7"
};
// clang-format on

const unsigned op_sizes[0x100] = {
	//    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	/*0*/ 1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
	/*1*/ 1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
	/*2*/ 1, 3, 3, 1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1,
	/*3*/ 1, 3, 3, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
	/*4*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*5*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*6*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*7*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*8*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*9*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*A*/ 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*B*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*C*/ 1, 1, 3, 3, 3, 1, 2, 1, 1, 1, 3, 1, 3, 3, 2, 1,
	/*D*/ 1, 1, 3, 2, 3, 1, 2, 1, 1, 1, 3, 2, 3, 1, 2, 1,
	/*E*/ 1, 1, 3, 1, 3, 1, 2, 1, 1, 1, 3, 1, 3, 3, 2, 1,
	/*F*/ 1, 1, 3, 1, 3, 1, 2, 1, 1, 1, 3, 1, 3, 3, 2, 1
};

#endif
