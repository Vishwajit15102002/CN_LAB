#include<stdio.h>
#include<conio.h>
int main()
{
	char s_data_NL[100]="\0", s_data_DLL[100]="\0",stuff[100]="\0";
	char r_data_NL[100]="\0", r_data_DLL[100]="\0";
	int i=0,j=0,k=0,s_count=1,r_count=1,x,s;
	clrscr();
	printf("Demo of Bit Stuffing:\n");
	printf("\nsender file");
		printf("\nEnter data to transmit:\n");
		scanf("%s",&s_data_NL);
		while(s_data_NL[i]!='\0')
		{
			if(s_data_NL[i]=='1')
			  {
				stuff[j]=s_data_NL[i];
				j++;
				s_count++;
				if(s_count==5)
				{
					stuff[j]='0';
					j++;
					s_count=0;
				}
			  }
			 else
			 {
				s_count=0;
				stuff[j]=s_data_NL[i];
				j++;


			 }
			 i++;
	       } //while end

	       strcat(s_data_DLL,stuff);
	       printf("Data transmitted to receiver is \n:");

	       puts(s_data_DLL);
	       sleep(10);
	       printf("\n Receiver side:");
	       strcpy(r_data_DLL,s_data_DLL);
	       puts(r_data_DLL );
	       x=strlen(r_data_DLL);
			for(i=0;i<=x;i++)
			{
			if(r_data_DLL[i]=='1')
			     {
			       r_data_NL[k]=r_data_DLL[i];
				r_count++;
				k++;
				if(r_count%5==0 && r_data_DLL[i+1]=='0')
				i++;
			      }
			      else
			      {
				r_count=0;
				r_data_NL[k]=r_data_DLL[i];
				k++;
			      }
			}
			getch() ;
			return 0;





 //getch();
// return 0;
}