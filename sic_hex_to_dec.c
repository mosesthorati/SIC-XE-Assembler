unsigned p000_hex2dec(char * math){

    int toInt(unsigned expon, int hex){
    int dec = 0;
        
   
        if(hex >= 48 && hex <= 57){
			dec = hex - 48;
		}
		
		else if(hex >= 65 && hex <= 70){
			dec = hex - 55;
		}
		
		else{
			dec = hex - 87;
		}
	
		
		int i;
		int base = 1;
		
		for(i = expon; i > 0; i--){
			base = base * 16;
		}
		
		return (unsigned)dec * base;
		
	}
	
	
	int hex;
	
	
	unsigned sum   = 0;
	unsigned expon = 0;
	int      len   = strlen(math);
	int      adr   = len - 1;
	
	for(; adr >= 0; adr--, expon++ ){
		hex = (int)math[adr];
		
		
		sum = sum + toInt(expon, hex);
	}
	
	return sum;
	
}

