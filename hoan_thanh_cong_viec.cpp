#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef double ll;


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
	// freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		ll a,x,b,y,n;
		scanf("%lf %lf %lf %lf %lf",&a,&x,&b,&y,&n);
		long long st=(long long)(n/(a*(x-1)/x+b*(y-1)/y));
		while (1)
		{ 
			long long tmp=a*(x-1)*((int)(st/x))+b*(y-1)*((int)(st/y))+a*(st%((int)(x)))+b*(st%((int)(y)));
			if (tmp>=n) st--;
			else break;
		}
		printf("%lld\n",st+1);
	}
}

