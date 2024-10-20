#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll n,m,p,q,a[1005][1005],b[1005][1005],c[1005][1005],res1[1005][1005],res2[1005][1005];

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
void process()
{
	//res1 : n*p;
	for (int i=1;i<=n;i++)	
		for (int j=1;j<=p;j++)
		{
			res1[i][j]=0;
			for (int k=1;k<=m;k++) res1[i][j]+=a[i][k]*b[k][j];
		}
	//res2 : n*q
	for (int i=1;i<=n;i++)
		for (int j=1;j<=q;j++)
		{
			res2[i][j]=0;
			for (int k=1;k<=p;k++) res2[i][j]+=res1[i][k]*c[k][j];
		}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=q;j++) printf("%lld ",res2[i][j]);
		printf("\n");
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	scanf("%lld %lld %lld %lld",&n,&m,&p,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=p;j++) scanf("%lld",&b[i][j]);
	for (int i=1;i<=p;i++)
		for (int j=1;j<=q;j++) scanf("%lld",&c[i][j]);
	process();
}

