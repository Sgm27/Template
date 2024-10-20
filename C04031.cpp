#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n,a[105];
struct mang{
	int l,r;
};
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
void process()
{
	int cnt=0,l1=1,r1=1,Max=-1;
	struct mang res[105];
	a[0]=-999999;
	while (r1<=n)
	{
		if (a[r1]>a[r1-1]) r1++;
		else 
		{
			if (r1-l1>Max) 
			{
				Max=r1-l1;
				cnt=1;
				res[cnt].l=l1;
				res[cnt].r=r1-1;
				l1=r1;
			}
			else
			if (r1-l1==Max)
			{
				cnt++;
				res[cnt].l=l1;
				res[cnt].r=r1-1;
				l1=r1;
			}
			else l1=r1;
			r1++;
		}
	}
	if (r1-l1>Max) 
	{
		Max=r1-l1;
		cnt=1;
		res[cnt].l=l1;
		res[cnt].r=r1-1;
		l1=r1;
	}
	else
	if (r1-l1==Max)
	{
		cnt++;
		res[cnt].l=l1;
		res[cnt].r=r1-1;
		l1=r1;
	}
	printf("%d\n",Max);
	for (int i=1;i<=cnt;i++) 
	{
		for (int j=res[i].l;j<=res[i].r;j++) printf("%d ",a[j]);
		printf("\n");
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	for (int stt=1;stt<=tc;stt++)
	{
		printf("Test %d:\n",stt);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		process();
	}
}

