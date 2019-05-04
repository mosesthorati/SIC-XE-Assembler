

short p131_isit_comment(char * allLine){
	short isCommentFalg;

 

	if( (allLine[ 0 ] == '.') || (allLine[ 1 ] == '.')){
		isCommentFalg = TRUE;
	}	
	else{
		isCommentFalg = FALSE;
	}
	
	return isCommentFalg;
}

