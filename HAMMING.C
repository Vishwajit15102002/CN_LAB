#include<stdio.h>
#include<unistd.h>
int main()
{
	long int entere_data;
	int data_array[11];
	int p1sum,p2sum,p8sum,p4sum;
	int c0sum,c1sum,c2sum,c3sum;
	int it=1,d,i,n;
	int c1,c2,c3,c4;
	int loc,eloc;
	int choice;
	printf("Sender side\n");
	printf("enter the 7 bit data");
	scanf("%ld",&entere_data);    //%ld for long int
	
    while(entere_data>0)
	{
		d=entere_data%10;
		entere_data=entere_data/10;
		if(it==1)
		{
			data_array[3]=d;
		}
		else if(it==2)
		{
			data_array[5]=d;
		}
		else if(it==3)
		{
			data_array[6]=d;
		}
		else if(it==4)
		{
			data_array[7]=d;
		}
		else if(it==5)
		{
			data_array[9]=d;
		}
		else if(it==6)
		{
			data_array[10]=d;
		}
		else
		{
			data_array[11]=d;
		}
		it++;	
	}
	
	p1sum=data_array[3]+data_array[5]+data_array[7]+data_array[9]+data_array[11];
    if(p1sum%2==0){
    	data_array[1]=0;
	}
    else{
    	data_array[1]=1;
	}	
		
	p2sum=data_array[3]+data_array[6]+data_array[7]+data_array[10]+data_array[11];
    if(p2sum%2==0){
    	data_array[2]=0;
	}
    else{
    	data_array[2]=1;
	}	
    	
	p4sum=data_array[6]+data_array[5]+data_array[7];
    if(p4sum%2==0){
        data_array[4]=0;	
	}
    else{
        data_array[4]=1;	
	}	
	
	p8sum=data_array[10]+data_array[9]+data_array[11];
    if(p8sum%2==0){
    	data_array[8]=0;
	}
    else{
    	data_array[8]=1;
	}	
		
	printf("Hamming code from sender side:\n");
	for(i=11;i>=1;i--)
	{
		printf("%d\t",data_array[i]);
	}
	sleep(5);
	printf("\nReceiver side\n");
	printf("Do you want to change a bit?\n 1 or 0\n");
	
	scanf("%d",&choice);
		
	if(choice== 1)
	{
		printf("enter the position of bit that you want to change");
		scanf("%d",&loc);
		if(data_array[loc]==1)
		{
			data_array[loc]=0;
	    }
		if(data_array[loc]==0)
		{
			data_array[loc]=1;
	    }
	}
	
	c1=data_array[1]+data_array[3]+data_array[5]+data_array[7]+data_array[11]+data_array[9];
	if(c1%2==0)
	{
		c0sum=0;
	}
	else
	{
		c0sum=1;
	}
	c2=data_array[2]+data_array[3]+data_array[6]+data_array[7]+data_array[10]+data_array[11];
	if(c2%2==0)
	{
		c1sum=0;
	}
	else
	{
		c1sum=1;
	}
	c3=data_array[4]+data_array[5]+data_array[6]+data_array[7];
	if(c3%2==0)
	{
		c2sum=0;
	}
	else
	{
		c2sum=1;
	}
	c4=data_array[8]+data_array[9]+data_array[10]+data_array[11];
	if(c4%2==0)
	{
		c3sum=0;
	}
	else
	{
		c3sum=1;
	}
	
	//we can also use XOR operation instead of above if-else to reduce size and simplicity of program
	
	//c2sum=data_array[4]^data_array[5]^data_array[6]^data_array[7];
	//c3sum=data_array[8]^data_array[9]^data_array[10]^data_array[11];
	
	eloc=c0sum*1+c1sum*2+c2sum*4+c3sum*8;	
	if(eloc==0)
	{
		printf("\nThere is no error in the data transmission");
		printf("\nData transferd is:\n");
		for(i=1;i<12;i++)
		{
			printf("%d\t",data_array[i]);
			
		}
	}
	else
	{
		printf("\nThere is error in the data transmission with location %d",eloc);
		printf("\nBefore error correction data is:\n");
		for(i=11;i>=1;i--)
		{
			printf("%d\t",data_array[i]);
		}
		if(data_array[eloc]==0)
		{
			data_array[eloc]=1;
		}
		else
		{
			data_array[eloc]=0;
		}
		printf("\nAfter correction data is:\n");
		for(i=11;i>=1;i--)
		{
			printf("%d\t",data_array[i]);
		}
		
	}
}
