// Dijkstra's Algorithm to find shortest Path
// refer the page 369 of Computer Networks -Tanenbaum 5th edition for concept and program

#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
int dist[MAX][MAX];
int path[20]={0};
int n;


int main()
{
struct state
{
 int predecessor;
 int length;
 enum {permanent , tentative}label;
}state[MAX];
struct state *p;
int i,k,min,j,s,t;;


printf("Enter the no. of nodes:");
scanf("%d",&n);
printf("\nEnter the distance adjacency matrix:\n");

printf("\n Note: Assume i to j and j to i distance is same distance\n ");
printf(" Assume that distance is 0 if there is no direct link is  present. \n");
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	    if(i==j)
	    {
	      dist[i][i]=0;
	    }
	    else
	    {
		printf("Enter distance between %d to %d : ", i,j);
		scanf("%d",&dist[i][j]);
	    }
	}
printf("\nEnter the starting node:");
scanf("%d",&s);
printf("enter the destination node :");
scanf("%d",&t);



for(p=&state[0];p<&state[n];p++)
{
p->predecessor=-1;
p->length=INFINITY;
p->label=tentative;
}
state[t].length=0;
state[t].label=permanent;
k=t;

do
{
for(i=0;i<n;i++)
  if(dist[k][i]!=0 && state[i].label==tentative)
  {
   if(state[k].length+dist[k][i]<state[i].length)
    {
     state[i].predecessor=k;
     state[i].length=state[k].length+dist[k][i];
    }
   }
k=0,min=INFINITY;

for(i=0;i<n;i++)
   if(state[i].label==tentative && state[i].length<min)
   {
   min=state[i].length;
   k=i;
   }
 state[k].label=permanent;
}while(k!=s);

// copy path
k=s;
do
{
printf("%d ",k);
k=state[k].predecessor;
}while(k>=0);

getch();
return 0;

}

/* output

 Note: Assume i to j and j to i distance is same distance
       Assume that distance is 0 if there is no direct link is  present.
Enter distance between 0 to 1 : 6
Enter distance between 0 to 2 : 1
Enter distance between 0 to 3 : 0
Enter distance between 0 to 4 : 0
Enter distance between 1 to 0 : 6
Enter distance between 1 to 2 : 2
Enter distance between 1 to 3 : 2
Enter distance between 1 to 4 : 6
Enter distance between 2 to 0 : 1
Enter distance between 2 to 1 : 2
Enter distance between 2 to 3 : 1
Enter distance between 2 to 4 : 0
Enter distance between 3 to 0 : 0
Enter distance between 3 to 1 : 2
Enter distance between 3 to 2 : 1
Enter distance between 3 to 4 : 5
Enter distance between 4 to 0 : 0
Enter distance between 4 to 1 : 6
Enter distance between 4 to 2 : 0
Enter distance between 4 to 3 : 5

Enter the starting node:0
enter the destination node :4
0 2 3 4
*/
