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


int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,cnt=0;
		scanf("%d",&n);
		for (int i=1;i<=sqrt(n);i++) 
			if (n%i==0)
			{
				if (i%2==0) cnt++;
				if (n/i %2==0) cnt++;
			}
		int tmp=sqrt(n);
		if (tmp*tmp==n && tmp%2==0) cnt--;
		printf("%d\n",cnt);
	}
}

