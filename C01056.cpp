#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;

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
int check(ll k)
{
	char tmp[25];
	sprintf(tmp,"%lld",k);
	for (int i=0;i<strlen(tmp)-1;i++)
		if (tmp[i]>tmp[i+1]) return 0;
	return 1;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		ll n;
		scanf("%lld",&n);
		if (check(n)) printf("YES\n");
		else printf("NO\n");
	}
}

