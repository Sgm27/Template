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
void uoc(int n)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (n%i==0)  cnt++;
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++)
		if (n%i==0)  printf("%d ",i);
	printf("\n");
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n;
		scanf("%d",&n);
		uoc(n);
	}
}

