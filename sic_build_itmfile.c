
#define DEBUG
void p130_built_itmfile(FILE * sicPgrm, SYMTABLE * Syms, Line ** Lines, INFOR * infor){


	Line * L;
	FILE *inter;
	inter = fopen("inter.txt","w");
	char     pgrmName [10];
	unsigned startLoc = 0;
	unsigned pgmLen   = 0;
	
	char     tmpLine    [ ALL_LEN + 1 ];
	unsigned nowLoc     =  0;
	unsigned countLines =  0;
	unsigned countSyms  =  0;


	short errorFlag     =  FALSE;
	short stopReadFlag  =  FALSE;
	
	int i = 0;

	memset(pgrmName,  '\0', sizeof(pgrmName));
	

	

	
	
	
	
	while(stopReadFlag == FALSE){
		
		
		memset(tmpLine,'\0', sizeof(tmpLine));
		L = NULL;
		
		
		
		if(fgets(tmpLine, ALL_LEN, sicPgrm) == NULL){
			stopReadFlag = TRUE;
			continue;
		}
			
		else if(p131_isit_comment(tmpLine) == TRUE){
			continue;
		}
		else{
		
			
			L = p110_init_line(tmpLine);
			
			
			p113_divi_in3part(L);
			
			
			Lines[countLines] = L;
			countLines++;
			
		}
		
	}
	
	
	
	strcpy(pgrmName,        Lines[0]->lable  );
	
	nowLoc = p000_hex2dec( Lines[0]->oprent );
	
	
	
	
	for(i = 1; i < countLines - 1; i++){
		L = Lines[ i ];

		
		if(L->eroMesg != NULL){
			
			L->locctr = 0xFFFF;
			continue;
			
		}else {
			
			
			if(L->lable != NULL){
				strcpy(Syms[ countSyms ].lable, L->lable);
				Syms[ countSyms ].locctr = nowLoc;
				countSyms++;
			}
			
		
			p114_find_code_in_table(L);
			
			

			if(L->eroMesg == NULL){

                L->locctr = nowLoc;
               
                if(L->subscript / OP_BASE == 1){
    				
    				
    				nowLoc = nowLoc + OPTABLE[ L->subscript - OP_BASE ].format;
    				
    				
    			
    			}else if(L->subscript / PI_BASE == 1){
    			
    			    unsigned shiftLoc = 0;
    				
    				shiftLoc = p115_process_picode(L);
    			   
                    nowLoc = nowLoc + shiftLoc;
                }
            	
			}
			
		}
	}
	
	
	
	
	pgmLen = nowLoc - p000_hex2dec( Lines[0]->oprent );
	
	
	
	unsigned loc = 0;
	unsigned adr = 0;
	
	
	L = Lines[ countLines - 1 ];
	
	if(L->oprent == NULL){
          
        
        startLoc =  p000_hex2dec( Lines[0]->oprent );
    }else{
      
        adr = p012_find_sym(Syms, L->oprent);
        
       
        if(adr != ERROR_VALUE){
            
            startLoc = Syms[ adr ].locctr;
        }else{
            
            p112_write_mesg(L, "-< can not find start Lable >-");
        }
        
    }

    strcpy(infor->pgmName, pgrmName);
    infor->startLoc = startLoc;
    infor->pgmLen   = pgmLen;
    infor->countLines = countLines;
    
    
    
 
    
/************************************ inter.txt ****************************************/
	for(i = 0; i < countLines; i++){
		L = Lines[ i ];
		
	
		if(i==0)
			fprintf(inter,"1000\t");
		else
    	       		fprintf(inter,"%4x\t", L->locctr);
			fprintf(inter,"%20s\n", L->all);
		
	}
	
    
 					
    fclose(inter);
    }
