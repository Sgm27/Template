#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll f[105];

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
	f[1]=1;
	f[2]=1;
	for (int i=3;i<=92;i++) 
		f[i]=f[i-1]+f[i-2];
}

int main()
{
	init();
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",f[n]);
	}
}

