#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int n,k;

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
	if ((k-1)%2==0) 
	{
		printf("1\n");
		return;
	}
	int cs1=1,cs2;
	for (int i=2;i<=n;i++)
	{
		cs1*=2;
		cs2=cs1*2;
		if ((k-cs1)%cs2==0)
		{
			printf("%d\n",i);
			return;
		}
	}
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d %d",&n,&k);
		process();
	}
}

