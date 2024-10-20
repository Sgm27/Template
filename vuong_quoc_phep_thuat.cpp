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
ll min(ll a,ll b)
{
	if (a>b) return b;
	return a;
}


int main()
{
	freopen("thu.inp","r",stdin);
	ll n,p,s1,s2;
	scanf("%lld %lld %lld %lld",&n,&p,&s1,&s2);
	if (s1+n*p<s2 || s2+n*p<s1)
	{
		printf("'N0'\n");
		printf("%d",abs(s1+n*p-s2));
		return 0;
	}
	if (s1+n*p==s2 || s2+n*p==s1)
	{
		printf("'YES'");
		return 0;
	}
	ll sum=n*p+s1+s2;
	ll sub_sum=sum/2;
	if ((sub_sum-s1)%p==0 && (sub_sum-s2)%p==0)
	{
		ll x=(sub_sum-s1)/p;
		ll y=(sub_sum-s2)/p;
		if (x+y==n) printf("'YES'");
		return 0;
	}
	printf("'N0'\n");
	ll min1,min2;
	min1=abs(((sub_sum-s1)/p+1)*p+s1-(sum-((sub_sum-s1)/p+1)*p-s1));
	min2=abs(((sub_sum-s2)/p+1)*p+s2-(sum-((sub_sum-s2)/p+1)*p-s2));
	printf("%lld",min(min1,min2));
}

