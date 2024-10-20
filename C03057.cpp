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
	ll res;
	char tmp1[150];
	char tmp2[150];
	sprintf(tmp1,"%lld",x);
	sprintf(tmp2,"%lld",y);
	//tim tong nho nhat
	for (int i=0;i<strlen(tmp1);i++)  
		if (tmp1[i]=='6') tmp1[i]='5';
	for (int i=0;i<strlen(tmp2);i++)  
		if (tmp2[i]=='6') tmp2[i]='5';
	res=atoll(tmp1)+atoll(tmp2);
	printf("%lld ",res);
	//tim tong nho nhat
	for (int i=0;i<strlen(tmp1);i++)  
		if (tmp1[i]=='5') tmp1[i]='6';
	for (int i=0;i<strlen(tmp2);i++)  
		if (tmp2[i]=='5') tmp2[i]='6';
	res=atoll(tmp1)+atoll(tmp2);
	printf("%lld\n",res);
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%lld",&tc);
	while (tc--)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		process(x,y);
	}
}

