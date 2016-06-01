#include<conio.h>
#include<stdio.h>
void singlesource(int n,int sv,int cost[50][50],int dist[50])
{
int i,temp,b,num,s[50],min;
for(i=1;i<=n;i++)
{
s[i]=0;
dist[i]=cost[sv][i];
}
for(num=2;num<=n-1;num++)
 {
min=1000;
for(b=1;b<=n;b++)
if(dist[b]<min)
{
min=dist[b];
temp=b;
}
s[temp]=1;
for(b=1;b<=n;b++)
if((dist[temp]+cost[temp][b])<dist[b])
dist[b]=dist[temp]+cost[temp][b];
}
}
void main()
{
int n,sv,i,j,c[50][50],d[50];
clrscr();
printf("\n Enter no of vertex");
scanf("%d",&n);
printf("\n Enter cost in matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&c[i][j]);
if(c[i][j]==0)
c[i][j]=1000;
}
printf("\n Enter starting vertex");
scanf("%d",&sv);
singlesource(n,sv,c,d);
printf("\n Shortest path\n");
for(i=1;i<=n;i++)
if(i!=sv)

printf("%d->%d,c=%d\n",sv,i,d[i]);
getch();
}