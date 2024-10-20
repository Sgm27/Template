#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll a,b,c,d;
ll gcd(ll a,ll b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
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
void process()
{
	//rut gon
	ll tmp=gcd(a,b);
	a/=tmp;
	b/=tmp;
	tmp=gcd(c,d);
	c/=tmp;
	d/=tmp;
	//quy dong
	ll mc1=lcm(b,d);
	a=a*(mc1/b); b=mc1;
	c=c*(mc1/d); d=mc1;
	printf("%lld/%lld %lld/%lld\n",a,b,c,d);
	//tong 
	ll tt=a+c;
	tmp=gcd(tt,mc1);
	tt/=tmp;
	mc1/=tmp;
	printf("%lld/%lld\n",tt,mc1);
	//thuong
	ll tu=a*d,mau=b*c;
	tmp=gcd(tu,mau);
	tu/=tmp;
	mau/=tmp;
	printf("%lld/%lld\n",tu,mau);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	for (int stt=1;stt<=tc;stt++)
	{
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		printf("Case #%d:\n",stt);
		process();
	}
}
