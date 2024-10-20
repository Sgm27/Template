#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll a[105],n;

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
	a[0]=0;
	a[1]=1;
	for (int i=2;i<=91;i++) a[i]=a[i-1]+a[i-2];
}

int main()
{
//	freopen("thu.inp","r",stdin);
	init();
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%lld",&n);
		int check=0;
		for (int i=0;i<=91;i++)
			if (a[i]==n) 
			{
				check=1;
				break;
			}
		if (check) printf("YES\n");
		else printf("NO\n");
	}
}

