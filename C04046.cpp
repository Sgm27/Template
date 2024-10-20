#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
const int Max=1e9;

int n,a[100005];
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
int cmp(void const *a,void const*b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
void process()
{
	qsort(a+1,n,sizeof(int),cmp);
	int min_dis=Max;
	for (int i=2;i<=n;i++) min_dis=min(min_dis,a[i]-a[i-1]);
	int cnt=0;
	for (int i=2;i<=n;i++) 
		if (a[i]-a[i-1]==min_dis) cnt++;
	printf("%d %d\n",min_dis,cnt);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		process();
	}
}

