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

int nto(int k)
{
	if (k==2 || k==3) return 1;
	if (k<2 || k%2==0 || k%3==0) return 0;
	int i=5;
	while (i<=sqrt(k))
	{
		if (k%i==0 || k%(i+2)==0) return 0;
		else i+=6;
	}
	return 1;
}
int check(int n)
{
	if (!nto(n)) return 0;
	int sum=0;
	while (n)
	{
		sum+=n%10;
		if (!nto(n%10)) return 0;
		n/=10;
	}
	if (!nto(sum)) return 0;
	return 1;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int x,y,cnt=0;
		scanf("%d %d",&x,&y);
		for (int i=x;i<=y;i++) 
			if (check(i)) cnt++;
		printf("%d\n",cnt);
	}
}

