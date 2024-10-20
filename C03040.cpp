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
int tong_cs(int k)
{
	int sum=0;
	while (k)
	{
		sum+=k%10;
		k/=10;
	}
	return sum;
}
int tong_ts(int k)
{
	int sum=0,i=2;
	while (k!=1)
	{
		while (k%i==0) 
		{
			sum+=tong_cs(i);
			k/=i;
		}
		i++;
	}
	return sum;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int n;
	scanf("%d",&n);
	if (tong_cs(n)==tong_ts(n)) printf("YES");
	else printf("NO\n");
}


