#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll n,m,a[1005][55],x,y;


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
void swap(ll *a,ll *b)
{
	ll tmp=*a;
	*a=*b;
	*b=tmp;
}

int main()
{
//	freopen("thu.inp","r",stdin);
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	scanf("%lld %lld",&x,&y);
	for (int i=1;i<=n;i++) swap(&a[i][x],&a[i][y]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) printf("%lld ",a[i][j]);
		printf("\n");
	}
}

