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
	int n,a[1005],max1=-1e9,max2=-1e9;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		max1=max(max1,a[i]);
	}
	for (int i=1;i<=n;i++)
		if (a[i]!=max1) max2=max(max2,a[i]);
	printf("%d %d",max1,max2);
}

