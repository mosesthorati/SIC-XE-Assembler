
Format3 * p010_init_format3(unsigned value){
    
    Format3 * c =  NULL;
	
	c = (Format3 *)malloc( sizeof(Format3) ); 
    
	c->opCode    = 0x0;
	c->disp      = 0x0;
	c->xMask     = 0x8000;
	c->objCode   = value;
	c->xFlag     = FALSE;
	
	return c;
}


void p011_delete_format3(Format3 * c){
    
    if(c != NULL){
        free(c);
    }
}



void p012_calcu_format3(Format3 * c){
	
	
	if(c->xFlag == TRUE){
		
		
		c->disp = c->disp | c->xMask;
	}
	
	c->objCode   =   c->opCode;
	c->objCode   <<= 16;
	c->objCode   =   c->objCode | c->disp;
	
}


