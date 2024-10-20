#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n,l,r;

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
int check_tn(int k)
{
	int i=1,a[15],nmax=0;
	while (k)
	{
		a[++nmax]=k%10;
		k/=10;
	}
	for (int i=1;i<=nmax/2;i++)
		if (a[i]!=a[nmax-i+1]) return 0;
	return 1;
}
int check_ten(int k)
{
	int sum=0;
	while (k)
	{
		sum+=k%10;
		k/=10;
	}
	if (sum%10==0) return 1;
	return 0;
}
int check(int k)
{
	if (check_tn(k) && check_ten(k)) return 1;
	return 0;
}

int main()
{
	//freopen("thu.inp","r",stdin);
	int tc,cnt;
	scanf("%d",&tc);
	while (tc--)
	{
		cnt=0;
		scanf("%d",&n);
		l=1;
		for (int i=1;i<=n-1;i++) l*=10;
		r=l*10-1;
		for (int i=l;i<=r;i++) 
			if (check(i)) cnt++;
		printf("%d\n",cnt);
	}
}

