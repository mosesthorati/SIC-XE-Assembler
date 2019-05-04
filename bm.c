#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int getint(char a);

void bitmask()
{
	FILE *p,*q;
	p=fopen("objpgm.txt","r");
	q=fopen("final.txt","w");
	char* line =malloc(100) ;
	
	while(fgets(line,100,p)!=NULL)
	{
		
		
		int k=strlen(line);
		if(line[0]=='H')
		{
			fprintf(q,"%s",line);

		}
		else if(line[0]=='T')
		{
			char a1=line[7];
			char a2=line[8];
			int i=(getint(a1)*16)+getint(a2);
			i=i/3;
			char s1[3];
			if(i==1)
			{
				char s11[3]={'8','0','0'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else if(i==2)
			{
				 char s11[3]={'C','0','0'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else if(i==3)
			{
				char s11[3]={'E','0','0'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else if(i==4)
			{
				char s11[3]={'F','0','0'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else if(i==5)
			{
				char s11[3]={'F','8','0'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else if(i==6)
			{
				char s11[3]={'F','C','0'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else if(i==7)
			{
				char s11[3]={'F','E','0'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else if(i==8)
			{
				char s11[3]={'F','F','0'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else if(i==9)
			{
				char s11[3]={'F','F','8'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
			else
			{
				char s11[3]={'F','F','C'};
				for(int i=0;i<3;i++)
					s1[i]=s11[i];
			}
		
			for(int j=0;line[j]!='\0';j++)//condition j<k+3.
			{
				if(j<9)
				{
					
					fprintf(q,"%c",line[j]);
				}
				else if (j<12 && j>8)
				{
					
					fprintf(q,"%c",s1[j-9]);
				}
				else
				{
					
					fprintf(q,"%c",line[j]);
				}
			}
		
		}
		else if(line[0]=='E')
		{
			fprintf(q,"%s",line);
		}
			
	}
	
	fclose(q);
	fclose(p);
	/************************** 	final.txt FILE	*********************************/


}

int getint(char a)
{
	if(a=='0')
		return 0;
	else if(a=='1')	
		return 1;
	else if(a=='2')
		return 2;
	else if(a=='3')
		return 3;
	else if(a=='4')
		return 4;
	else if(a=='5')
		return 5;
	else if(a=='6')
		return 6;
	else if(a=='7')
		return 7;
	else if(a=='8')
		return 8;
	else if(a=='9')
		return 9;
	else if(a=='a')
		return 10;
	else if(a=='b')
		return 11;
	else if(a=='c')
		return 12;
	else if(a=='d')
		return 13;
	else if(a=='e')
		return 14;
	else if(a=='f')
		return 15;
	else
		return 0;
}


