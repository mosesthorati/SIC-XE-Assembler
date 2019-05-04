

unsigned p010_find_opcode(char * temp){
	unsigned subscript = 0;
	
	for(; subscript < OPTABLE_LEN; subscript++){
		if(strcmp(temp, OPTABLE[ subscript ].name) == 0){
			break;
		}
	}
	
	
	if(subscript >= OPTABLE_LEN){
		subscript = ERROR_VALUE;
	}
	
	return subscript;
}


unsigned p011_find_pi(char * temp){
	unsigned subscript = 0;
	
	for(; subscript < PSEUDO_INS_LEN; subscript++){
		if(strcmp(temp, PITABLE[ subscript ]) == 0){
			break;
		}
	}
	
	
	if(subscript >= PSEUDO_INS_LEN){
		subscript = ERROR_VALUE;
	}
	
	return subscript;
}


unsigned p012_find_sym(SYMTABLE *Syms, char * temp){
	unsigned subscript = 0;
	
	for(; subscript < SYM_LEN; subscript++){
		if(strcmp(temp, Syms[ subscript ].lable) == 0 ){
			break;
		}
	}
	

	if(subscript >= SYM_LEN){
		subscript = ERROR_VALUE;
	}
	
	return subscript;
}


