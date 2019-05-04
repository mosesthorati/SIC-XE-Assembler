#include "pgrmhead.c"
#include "bm.c"

#include "sic_find_tables.c"
#include "sic_hex_to_dec.c"
#include "sic_format3.c"

#include "sic_line.c"



#include "sic_open_sicpgrm.c"

#include "sic_build_itmfile_functions.c"

#include "sic_build_itmfile.c"

#include "sic_gener_f3.c"

#include "sic_output_objpgm.c"

int main(void){
	
	int i = 0;
	unsigned countLines = 0;



	SYMTABLE Syms[ SYM_LEN ];
	
	

	Line * Lines[ LINES_LEN ];
	
	
	INFOR infor;
	
	
	

	memset(Lines,        0, sizeof(Lines));
	
	for(i = 0; i < SYM_LEN; i++){
		memset(Syms[ i ].lable, '\0', sizeof(Syms[ i ].lable));
		Syms[ i ].locctr = 0;
	}
	

	memset(infor.pgmName, '\0', sizeof(infor.pgmName));
	infor.countLines  = 0;
	infor.pgmLen      = 0;
	infor.startLoc    = 0;
	
	
	
	static FILE * sicPgrm;

	sicPgrm = fopen("sicpgrm.txt", "r");
	

	p130_built_itmfile( sicPgrm, Syms, Lines, &infor);
	
	fclose(sicPgrm);
	
	p200_gener_f3_objcode(Syms, Lines, infor.countLines);
    p210_output_objpgrm(Syms, Lines, &infor);
	
	Line * L;
	for(i = 0; i < LINES_LEN; i++){
		L = Lines[i];
		if(L != NULL){
			p111_delete_line(L);
		}
	}
	
	//system("pause");
	bitmask();
	
	
	return 0;
}

