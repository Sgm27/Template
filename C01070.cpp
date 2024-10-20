#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int max(int a,int b)
{
	if (a>b) return a;
	return b;
}
int min(int a,int b)
{
	if (a>b) return b;
	return a;
}
int cp(int k)
{
	int tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int res=0,sum=0,Max=-1,cs=-1,d[105]={0};
	for (int i=1;i<=3;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if (x>Max) 
		{
			Max=x;
			cs=y;
		}
		if (y>Max)
		{
			Max=y;
			cs=x;
		}
		sum+=x+y;
		res+=x*y;
		d[x]++; d[y]++;
	}
	sum+=cs;
	if (cp(res) && Max==sqrt(res) && d[Max]==1 && sum%4==0 && sum/4==Max) printf("YES");
	else printf("NO");
}
