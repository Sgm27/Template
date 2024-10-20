#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll a[1005][1005],b[1005][1005],tmp[1005][1005],n,m;
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
void nhan()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 
		{
			ll sum=0;
			for (int k=1;k<=m;k++) sum+=a[i][k]*b[k][j];
			tmp[i][j]=sum;
		}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) printf("%lld ",tmp[i][j]);
		printf("\n");
	}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	for (int stt=1;stt<=tc;stt++)
	{
		printf("Test %d:\n",stt);
		scanf("%lld %lld",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) b[j][i]=a[i][j];
		nhan();
	}
}

