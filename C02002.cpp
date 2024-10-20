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


int main()
{
//	freopen("thu.inp","r",stdin);
	int n,m;
	scanf("%d",&n);
	m=n-1;
	for (int stt=1;stt<=n;stt++)
	{
		for (int i=1;i<=m;i++) printf("~");
		for (int i=1;i<=n;i++) printf("*");
		m--;
		printf("\n");	
	}
}

