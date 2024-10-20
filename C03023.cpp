#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int check_tn(int k)
{
	int i=1,a[15],nmax=0;
	while (k)
	{
		a[++nmax]=k%10;
		if (k%10==9) return 0;
		k/=10;
	}
	for (int i=1;i<=nmax/2;i++)
		if (a[i]!=a[nmax-i+1]) return 0;
	return 1;
}
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
//	freopen("thu.inp","r",stdin);
	int n,cnt=0;
	scanf("%d",&n);
	for (int i=2;i<=n;i++) 
		if (check_tn(i))
		{
			printf("%d ",i);
			cnt++;
		}
	printf("\n%d",cnt);
}

