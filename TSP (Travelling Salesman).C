#include<stdio.h>
#include<conio.h>
int a[5][5],visited[10],n,cost=0;

void get()
{
int i,j;
printf("enter no. of nodes: ");
scanf("%d",&n);
printf("\n enter matrix: \n");
for( i=0;i<n;i++)
{
for( j=0;j<n;j++)
scanf("\t%d",&a[i][j]);
visited[i]=0;
}
printf("\nThe cost list is:\n\n");
for( i=0;i<n;i++)
{
printf("\n\n");
for( j=0;j<n;j++)
printf("%d",a[i][j]);
}
}

void mincost(int node)
{
int i,nnode;
visited[node]=1;
printf("%d ",node+1);
nnode=least(node);
if(nnode==999)
{
nnode=0;
printf("%d",nnode+1);
cost+=a[node][nnode];
return;
}
mincost(nnode);
}

int least(int c)
{
int i,nc=999;
int min=999,kmin;
for(i=0;i<n;i++)
{
if((a[c][i]!=0)&&(visited[i]==0))
if(a[c][i]<min)
{
min=a[i][0]+a[c][i];
kmin=a[c][i];
nc=i;
}
}
if(min!=999)
cost+=kmin;
return nc;
}

void put()
{
printf("\n\nMinimum cost");
printf("%d",cost);
}
void main()
{
clrscr();
get();
printf("\n\nthe path is:");
mincost(0);
put();
getch();
}