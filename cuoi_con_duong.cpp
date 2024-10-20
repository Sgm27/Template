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
	freopen("thu.inp","r",stdin);
	ll step;
	scanf("%lld",&step);
	if (step>=128888888888889) 
		printf("%lld",9999999999999+(step-128888888888889)/14+((step-128888888888889)%14!=0));
	else
	if (step>=11888888888889)
		printf("%lld",999999999999+(step-11888888888889)/13+((step-11888888888889)%13!=0));
	else
	if (step>=1088888888889)
		printf("%lld",99999999999+(step-1088888888889)/12+((step-1088888888889)%12!=0));
	else
	if (step>=98888888889)
		printf("%lld",9999999999+(step-98888888889)/11+((step-98888888889)%11!=0));
	else
	if (step>=8888888889)
		printf("%lld",999999999+(step-8888888889)/10+((step-8888888889)%10!=0));
	else
	if (step>=788888889)
		printf("%lld",99999999+(step-788888889)/9+((step-788888889)%9!=0));
	else
	if (step>=68888889)
		printf("%lld",9999999+(step-68888889)/8+((step-68888889)%8!=0));
	else
	if (step>=5888889)
		printf("%lld",999999+(step-5888889)/7+((step-5888889)%7!=0));
	else
	if (step>=488889)
		printf("%lld",99999+(step-488889)/6+((step-488889)%6!=0));
	else
	if (step>=38889)
		printf("%lld",9999+(step-38889)/5+((step-38889)%5!=0));
	else
	if (step>=2889)
		printf("%lld",999+(step-2889)/4+((step-2889)%4!=0));
	else
	if (step>=189)
		printf("%lld",99+(step-189)/3+((step-189)%3!=0));
	else
	if (step>=9)
		printf("%lld",9+(step-9)/2+((step-9)%2!=0));
	else
		printf("%lld",step);
}

