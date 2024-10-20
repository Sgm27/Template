#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll f[150];

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
void init()
{
	f[0]=0;
	f[1]=1;
	for (int i=2;i<=90;i++) f[i]=f[i-1]+f[i-2];
}

int main()
{
	//freopen("thu.inp","r",stdin);
	init();
	ll n;
	scanf("%lld",&n);
	for (int i=1;i<=90;i++)
		if (f[i]==n) 
		{
			printf("1");
			return 0;
		}
	printf("0");
}

