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
	//freopen("thu.inp","r",stdin);
	int n,m,p,a[1005],b[1005];
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	scanf("%d",&p);
	for (int i=1;i<=p;i++) printf("%d ",a[i]);
	for (int i=p+1;i<=p+m;i++) printf("%d ",b[i-p]);
	for (int i=p+1;i<=n;i++) printf("%d ",a[i]);
}

