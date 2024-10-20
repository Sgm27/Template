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
int check(int k)
{
	int sum=0;
	while (k)
	{
		sum+=k%10;
		k/=10;
	}
	if (sum%5==0) return 1;
	return 0;
}
int nto(int k)
{
	if (k==2 || k==3) return 1;
	if (k<2 || k%2==0 || k%3==0) return 0;
	int i=5;
	while (i<=(int)(sqrt(k)))
	{
		if (k%i==0 || k%(i+2)==0) return 0;
		else i+=6;
	}
	return 1;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int n,cnt=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		if (check(i) && nto(i)) 
		{
			printf("%d ",i);
			cnt++;
		}
	printf("\n%d",cnt);
}

