#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int j,k,i,r_len,g_len;
char g[33]="\0",m[1500]="\0",r[1500]="\0",t[1500]="\0",r_m[1500]="\0";
void crc(char m[1500])
{
	while(strlen(r) >=g_len)
	{
		j=0,k=0;
		for(i=0;i<g_len;i++)
		{
	    	r[i]=(r[i]==g[i] ? '0' : '1');			
			
	    }
		if(strlen(r)>=strlen(g))
		{
		 printf("\nEnter xor with generator:%s\n",g);
		 printf("Enter result after xor opration:%s\n",r);
	    }   
		strset(t,'\0');
		for(i=0;r[i]!='\0';i++)
		{
		    	if(r[i]=='0')
			    {
				j++;
				if(strlen(r)-j<g_len)
				{
					break;
		     	}
		        }
		 	    else
			    {
		    	break;
		        }
		 
	    }
		for(i=j,k=0;r[i]!='\0';i++,k++)
        {
			t[k]=r[i];		
		}
		strset(r,'0');
		strcpy(r,t);
		printf("\nEnter xor result without zeros:\t%s",r);
	}
}
int main()
{
	printf("Enter message:\n");
	scanf("%s",&m);
	strcpy(r,m);
	printf("Enter generator:\n");
	scanf("%s",&g);
	r_len=strlen(r);
	g_len=strlen(g);
	if(r_len<=g_len)
	{
		printf("Select appropriate generator :\n");
		return 0;
		exit(0);
	}
	for(i=0;i<g_len-1;i++,r_len++)
	{
		r[r_len]='0';
	}
	printf("\n Enter the appended zeros in message:%s",r);
	crc(r);
	strcat(m,r);
	printf("\nenter CRC:\t%s",m);
	//receiver side
	printf("\n Display modify data :\n");
	scanf("%s",r_m);
	
	
	strcpy(r,r_m);
	printf("\n The received message from sender:%s\n",r);
    crc(r_m);
    j=0;
	for( i=0;i<strlen(r);i++)
	{ 
		if(r[i]!='0')
		{	
		j++;
	    }
	}
	    if(j==0)
	    {
		printf("\n There is no error:");
		r_m[strlen(r_m)-(g_len-1)]='\0';
		printf("\n Actual message is:%s",r_m);
	    }
	    else
	    {
		printf("\nReceived message contain errors:");
	    }
	return 0;
}