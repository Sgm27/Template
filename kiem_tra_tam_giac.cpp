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
	ll a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	int check=0;
	if (a+b>c && b+c>a && a+c>b) check=1;
	if (!check) 
	{
		printf("NO.");
		return 0;
	} 	
	if (a==b && b==c) 
	{
		printf("DEU");
		return 0;
	}
	if (a==b || b==c || c==a)
	{
		printf("CAN");
		return 0;
	}
	if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b)
	{
		printf("VUONG");
		return 0;
	}
	printf("THUONG");
}

