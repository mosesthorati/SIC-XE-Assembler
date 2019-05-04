
FILE * p120_open_sicpgrm(void){
	char fileName[20];
	FILE * fileStream = NULL;
	short openSuccess = FALSE;
	
	
	while(openSuccess == FALSE){
		printf("------------------------------------\n");
		printf("SIC> Open SIC program file (.txt):");
		scanf("%s", fileName);
		
		if(NULL == (fileStream = fopen(fileName, "r")) )
		{
			puts("Can't find your file.");
			openSuccess = FALSE;
		} 
		else
		{		
			printf("Open Success!\n");
			openSuccess = TRUE;
		}
	}
	
	return fileStream;
}

