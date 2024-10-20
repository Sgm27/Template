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
	int a,b,v;
	scanf("%d %d %d",&a,&b,&v);
	if (a==v) printf("1");
	else
	{
		int tmp1=v-a;
		int tmp2=a-b;
		if (tmp1%tmp2==0)
			printf("%d",tmp1/tmp2+1);
		else
			printf("%d",tmp1/tmp2+2);
	}
}

