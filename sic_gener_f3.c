
void p200_gener_f3_objcode(SYMTABLE * Syms, Line ** Lines, unsigned countLines){
    
   
	Line    * L  = NULL;
	Format3 * F3 = NULL;
	
	
	int i = 0;
	unsigned opTableAdr  = 0;
	unsigned symTableAdr = 0;
	unsigned len         = 0;
	
	char lable [LABLE_LEN + 1];

	memset(lable,'\0', sizeof(lable));
	
	
	
	for(i = 1; i < countLines - 1; i++){
	    
		L = Lines[ i ];
		
		if(L->subscript / OP_BASE == 1){
		    
		    opTableAdr = L->subscript - OP_BASE;
		    
		    
            F3 = p010_init_format3(0);
            F3->opCode = OPTABLE[ opTableAdr ].opCode;
            
		    
		    if(opTableAdr == 16){
		           
		        F3->disp   = 0x0;
            }else{
                
      
		        len = strlen(L->oprent);
		    
		        if(L->oprent[len - 1] == 'X'){
		            
		            F3->xFlag = TRUE;
		            
		          
		            strncpy(lable, (char *)(&L->oprent[0]), len -2 );
		            symTableAdr = p012_find_sym(Syms, lable);
                }else{
                    
                    symTableAdr = p012_find_sym(Syms, L->oprent);
                }
		        
		        
                
                F3->disp = Syms[ symTableAdr ].locctr;
		        
            }
            
            
         
            p012_calcu_format3(F3);
            
           
            L->format3 = F3;
            
        }
	}
	
}

