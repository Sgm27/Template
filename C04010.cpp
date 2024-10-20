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


int main()
{
//	freopen("thu.inp","r",stdin);
	int min1=1e9,min2=1e9,n,a[1005];
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		min1=min(min1,a[i]);
	}
	for (int i=1;i<=n;i++)
		if (a[i]!=min1) min2=min(min2,a[i]);
	printf("%d %d",min1,min2);
}

