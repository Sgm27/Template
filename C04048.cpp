#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n,m,k,a[1005],d[10005];

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
int them(int a,int b)
{
	if (a%b!=0) return 1;
	return 0;
}
int main()
{
	freopen("thu.inp","r",stdin);
	memset(d,0,sizeof(d));
	scanf("%d %d %d",&n,&m,&k);
	if (k==0)
	{
		printf("%d",n-m);
		return 0;
	}
	for (int i=1;i<=m;i++) 
	{
		scanf("%d",&a[i]);
		for (int x=max(a[i]-k,1);x<=a[i]+k;x++) d[x]=1;
	}
	int res=0,cnt=0;
	d[n+1]=1;
	for (int i=1;i<=n+1;i++)
		if (d[i]==0) cnt++;
		else
		{
			if (cnt) res+=(int)(cnt/(2*k+1))+them(cnt,2*k+1);
			cnt=0;
		} 
	printf("%d",res);
}
