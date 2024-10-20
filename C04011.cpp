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
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,a[1005],cnt=0,Max[1005];
		scanf("%d",&n);
		Max[0]=-1;
		for (int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			Max[i]=max(Max[i-1],a[i]);
		}
		for (int i=1;i<=n;i++) 
			if(a[i]>=Max[i-1]) cnt++;
		printf("%d\n",cnt);
	}
}
