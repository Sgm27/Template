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
void process(ll x,ll y)
{
	ll l=0,r=abs(x-y),step=0;
	while (l<r)
	{
		++step;
		l+=step;
		r-=step;
	}
	l-=step;
	r+=step;
	if (r-l>step) printf("%lld\n",2*(step-1)+2);
	else printf("%lld\n",2*(step-1)+1);
}
int main()
{
	// freopen("thu.inp","r",stdin);
	ll x,y;
	while (scanf("%lld %lld",&x,&y)!=-1)
	{
		process(x,y);
	}
}

