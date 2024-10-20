#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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
int check(int n)
{
	char tmp[50];
	sprintf(tmp,"%d",n);
	if (tmp[0]==tmp[strlen(tmp)-1]) return 1;
	return 0;
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n;
		scanf("%d",&n);
		if (check(n)) printf("YES\n");
		else printf("NO\n");
	}
}

