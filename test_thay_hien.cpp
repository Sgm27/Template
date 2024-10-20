#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(long long a[][105],long long n,long long m)
{
	int d[105];
	memset(d,1,sizeof(d));
	for (int i=1;i<=m-1;i++)
		if (d[i])
		{
			for (int j=i+1;j<=m;j++) 
				if (a[1][j]==a[1][i]) d[j]=0;
		}
	if (n==1)
	{
		for (int i=1;i<=m;i++)
			if (d[i]) printf("%lld ",a[1][i]);
		printf("\n");
		return;
	}
	int check_res=0;
	for (int i=1;i<=m;i++)
		if (d[i])
	{
		long long moc=a[1][i];
		int is_true=0;
		for (int hang=2;hang<=n;hang++)
		{
			int check=0;
			for(int j=1;j<=m;j++)
				if (a[hang][j]==moc) 
				{
					check=1;
					break;
				}
			if (!check) break;
			if (hang==n) 
			{
				is_true=1;
				break;
			}
		}
		if (is_true) 
		{
			check_res=1;
			printf("%lld ",moc);
		}
	}
	if (!check_res) printf("-1");
	printf("\n");
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		long long n,m,a[105][105];
		scanf("%lld %lld",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
		solve(a,n,m);
	}
}