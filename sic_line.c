

Line * p110_init_line(char * allLine){
	Line * L =  NULL;
	
	L = (Line *)malloc( sizeof(Line) ); 
	
	
	L->all = malloc( sizeof(char) * (ALL_LEN  + 1) );
	strcpy(L->all, allLine);
	
	
	L->lable    = NULL;
	L->code     = NULL;
	L->oprent   = NULL;
	
	
	L->locctr    = 0;
	L->subscript = 0;
	
	
	L->format3 = NULL;
	
	L->bytes   = NULL;
	L->ascii   = NULL;
	
	
	L->eroMesg  = NULL;
	return L;
}



void p111_delete_line(Line * L){
    
   
	if(L->all != NULL)
		free(L->all);
    
 
	if(L->lable != NULL)
		free(L->lable);
		
	
    if(L->code != NULL)
		free(L->code);

 		
	if(L->oprent != NULL)
		free(L->oprent);
	
	
    if(L->bytes != NULL)
		free(L->bytes);
		

    if(L->format3 != NULL)
		free(L->format3);
	

	if(L->ascii != NULL)
		free(L->ascii);
    

	if(L->eroMesg != NULL)
		free(L->eroMesg);
		
	free(L);	

}




void p112_write_mesg(Line * L, char * mesg){
	
	if(L->eroMesg == NULL){
		L->eroMesg = malloc( sizeof(char) * (ERROR_LEN  + 1) );
		memset(L->eroMesg, '\0', sizeof(L->eroMesg));
	}
	
	strcat(L->eroMesg, mesg);
}




void p113_divi_in3part(Line * L){

	 
	char * tab1          = NULL;
	char * tab2          = NULL;
	char * newline       = NULL;
	char * front_opcode  = NULL;
	char * front_oprent  = NULL;
	
	
	
	tab1 = strchr(L->all,    9);
	
	
	if(tab1 == 0){

		p112_write_mesg(L, "-< this line is illegal >-");
		return;
		
	}else if(tab1 == L->all){
	
		L->lable = NULL;
	}else{
		
		L->lable = malloc( sizeof(char) * (LABLE_LEN  + 1) );
		memset(L->lable,  '\0', sizeof(L->lable));
		strncpy(L->lable, L->all, (tab1 - L->all));
	}
	
	

	front_opcode = tab1 + 1;
	
	tab2    = strchr(front_opcode,  9);
	
	newline = strchr(front_opcode,  10);
	
	
	
	if(tab2 == 0){
	
		
		L->code = malloc( sizeof(char) * (CODE_LEN   + 1) );
		memset(L->code,  '\0', sizeof(L->code));
		strncpy(L->code, front_opcode, (newline - front_opcode));	
	}
	else{
		front_oprent = tab2 + 1;
		
		L->code   = malloc( sizeof(char) * (CODE_LEN   + 1) );
		L->oprent = malloc( sizeof(char) * (OPRENT_LEN + 1) );
		
		memset(L->code,    '\0', sizeof(L->code  ));
		memset(L->oprent,  '\0', sizeof(L->oprent));
		
		strncpy(L->code,   front_opcode, (tab2    - front_opcode));
		strncpy(L->oprent, front_oprent, (newline - front_oprent));
	
	}
	
	#ifdef DEBUG
	
	#endif

}









void p114_find_code_in_table(Line * L){
    char     * temp      = NULL;       
	unsigned   subscript = 0;
	
	temp = L->code;
	
	subscript = p010_find_opcode(temp);
	
	if(subscript != ERROR_VALUE){
	    
	    subscript = subscript + OP_BASE;
	    L->subscript = subscript;
	    
    }else{
        
        
        subscript = p011_find_pi(temp);
        if(subscript != ERROR_VALUE){
	    
	       subscript = subscript + PI_BASE;
	       L->subscript = subscript;
     	}else{
     	    
     	    L->subscript  = ERROR_VALUE;
 	        L->locctr     = 0xFFFF;
	        p112_write_mesg(L, "-< opcode or picode is illegal >-");
       }
        
    }
	
	
	
}


unsigned p115_process_picode(Line * L){
	
	unsigned  shiftLoc = 0;
	unsigned  objLen   = 0;
	char      oprent   [OPRENT_LEN + 1 ];
	
	
	memset(oprent,      '\0', sizeof(oprent  ));
    strcpy(oprent, L->oprent);
    
    
  
    if(L->subscript - PI_BASE == BYTE){
        
        objLen = strlen(oprent);
        char *temp = NULL;
 
      
        temp = malloc( sizeof(char) * ( (objLen - 3)+ 1) );
        memset(temp,  '\0', sizeof(temp));
        
        
        strncpy(temp, (char *)(&oprent[2]), objLen -3 );
        
        
        if(oprent[0] == 'C'){
            
            L->ascii = temp;
            
            shiftLoc = strlen(temp) * 2;
            
        }else if(oprent[0] == 'X'){
            
            L->bytes = temp;
            
            shiftLoc = strlen(temp) / 2;
        }
       
   
   
   
    
    }else{
        
        unsigned  intValue = 0;
	    char      strValue [OPRENT_LEN + 1 ];
        
        
	    memset(strValue,    '\0', sizeof(strValue));
        
      
        if(oprent[0] == 'X'){
    	    
    	    objLen = strlen(oprent);
    	    
    	    
    	    strncpy(strValue, (char *)(&L->oprent[2]), objLen -3 );
    	    
    	   
    	    intValue = p000_hex2dec(strValue);
            
        }else{
            
            intValue = (unsigned)atoi(oprent);
        }
            
        
        
        
        switch(L->subscript - PI_BASE){
    	    
            case WORD:
              
                L->format3 = p010_init_format3(intValue);
                shiftLoc = 3;
                break;
    	        
            case RESB:
                
                shiftLoc = intValue;
                break;
                
            case RESW:
                
                shiftLoc = intValue * 3;
                break;
           
           case END:
                
                shiftLoc = 0;
                break;
                
           default:
               p112_write_mesg(L, "-< Error in  pass1_process_picode(Line * L)>-");
                
        }
	
        
    }
    
	
	return shiftLoc;
}



