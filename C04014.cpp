#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int d[10005];

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


int main()
{
//	freopen("thu.inp","r",stdin);
	memset(d,1,sizeof(d));
	int n,a[1005];
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		if (d[i])
		{
			int cnt=0;
			for (int j=i;j<=n;j++) 
				if (a[i]==a[j])
				{
					cnt++;
					d[j]=0;
				}
			printf("%d %d\n",a[i],cnt);
		}
}

