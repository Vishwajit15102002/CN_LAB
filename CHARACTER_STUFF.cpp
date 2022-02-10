//

#include<stdio.h>
#include<string.h>


int main()
{
 char s_dataNL[100]="\0", s_dataDLL[100]="\0",stuff[100]="\0";
 char r_dataNL[100]="\0", r_dataDLL[100]="\0";

 int i=0,j=0,k=0,s_count=0,r_count=0,x,s;
 printf("Demonstrationof Character stuffing ::::");
 printf("\nSender side");
	printf("\nEnter data to Transmit:\n ");
	scanf("%s",s_dataNL);
	stuff[0]='s';
	j++;
	   while(s_dataNL[i]!='\0')
	   {

		if(s_dataNL[i]=='s'||s_dataNL[i]=='x'||s_dataNL[i]=='e')
		 {
		     stuff[j]='x';
		     j++;
		    stuff[j]=s_dataNL[i];
		    j++;

		 }
		 else
		  {

		       stuff[j]=s_dataNL[i];
		       j++;
		  }
		 if(s_dataNL[i+1]=='\0')
		  {
		   stuff[j]='e';
		  }
		i++;
	   }

	   strcat(s_dataDLL,stuff);


   printf("\n\tThe data transmitted to RECIEVER is :\n");
   puts(s_dataDLL);

 printf("\n Receiver Side ::::");

  printf("\n\n\tThe data received from SENDER is:\n");
  strcpy(r_dataDLL,s_dataDLL);
  puts(r_dataDLL);
  x=strlen(r_dataDLL);
	   for(i=1;i<=x-2;i++)
	    {
	       if(r_dataDLL[i]=='x')
		{
		  i++;
		  r_dataNL[k]=r_dataDLL[i];
		  k++;
		}
	       else
	       {
		  r_dataNL[k]=r_dataDLL[i];
		  k++;
	       }

	    }
	 printf("\nOriginal data is :\n");
	 puts(r_dataNL);
 return 0;
}

