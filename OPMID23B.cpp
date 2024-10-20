#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int n,k,a[100005],d[105];
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

void input()
{
	memset(d,0,sizeof(d));
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]%=k;
		d[a[i]]++;
	}
	int res=n,chan=0;
	if (d[0]) res=res-d[0]+1;
	if (k%2==0) chan=1;
	for (int i=1;i<=k/2;i++)
	{
		if (chan && i==k/2 && d[i]) res=res-d[i]+1;
		else res-=min(d[i],d[k-i]);
	}
	printf("%d\n",res);
}


int main()
{
//	freopen("thu.inp","r",stdin);
	input();
}

