#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE   1
#define FALSE  0


#define OPTABLE_LEN      26
#define PSEUDO_INS_LEN   6


#define ALL_LEN      60
#define LABLE_LEN    10
#define CODE_LEN     10
#define OPRENT_LEN   10
#define ERROR_LEN    200


#define LINES_LEN  100
#define SYM_LEN    50


#define OP_BASE      100
#define PI_BASE      200
#define ERROR_VALUE  999


#define START  0
#define BYTE   1
#define WORD   2
#define RESB   3
#define RESW   4
#define END    5


struct opTable{
  	char     name     [LABLE_LEN + 1];
  	
	
	              
	unsigned opCode     : 8;
	
	
	unsigned format     : 2;
};

const struct opTable OPTABLE[ OPTABLE_LEN ] = {
	
	{ "ADD",0x18,3 },	{ "AND",0x40,3 },	{ "COMP",0x28,3 },	{ "DIV",0x24,3 },
	{ "J",0x3C,3 },		{ "JEQ",0x30,3 },	{ "JGT",0x34,3 },	{ "JLT",0x38,3 },
	{ "JSUB",0x48,3 },	{ "LDA",0x00,3 },	{ "LDCH",0x50,3 },	{ "LDL",0x08,3 },
	{ "LDX",0x04,3 },	{ "MUL",0x20,3 },	{ "OR",0x44,3 },	{ "RD",0xD8,3 },
	{ "RSUB",0x4C,3 },	{ "STA",0x0C,3 },	{ "STCH",0x54,3 },	{ "STL",0x14,3 },
	
	
	{ "STSW",0xE8,3 },	{ "STX",0x10,3 },	{ "SUB",0x1C,3 },	{ "TD",0xE0,3 },
	{ "TIX",0x2C,3 },	{ "WD",0xDC,3 }	
};





const char * PITABLE[ PSEUDO_INS_LEN ]
		= {"START", "BYTE", "WORD", "RESB", "RESW", "END" };






typedef struct symtable{
	char     lable     [LABLE_LEN + 1];
	unsigned locctr   : 16;
} SYMTABLE;


typedef struct Information{
	char     pgmName [LABLE_LEN + 1];
	unsigned startLoc;
	unsigned pgmLen;
	unsigned countLines;
} INFOR;


typedef struct FORMAT3 {
	
	unsigned opCode     : 8;
	
	
	unsigned disp       : 16;
	
	
	unsigned xMask      : 16;
	
	
	unsigned objCode    : 24;
	
	
	short xFlag;
	
} Format3;



typedef struct line{
	
	char * all;
	
	char * lable;
	char * code;
	char * oprent;
	

	
	unsigned locctr       : 16;
	
	unsigned subscript;
	
	
	
	Format3 * format3;
	
	
	
	char *    bytes;
	char *    ascii;
	
	
	
	char *   eroMesg;
	
} Line;



