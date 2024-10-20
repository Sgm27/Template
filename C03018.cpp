#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll f[150];

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
void init()
{
	f[0]=0;
	f[1]=1;
	for (int i=2;i<=50;i++) f[i]=f[i-1]+f[i-2];
}
int nto(int k)
{
	if (k==2 || k==3) return 1;
	if (k<2 || k%2==0 || k%3==0) return 0;
	int i=5;
	while (i<=(int)(sqrt(k)))
	{
		if(k%i==0 || k%(i+2)==0) return 0;
		else i+=6;
	}
	return 1;
}
int check(int k)
{
	if(!nto(k)) return 0;
	int sum=0;
	while (k)
	{
		int tmp=k%10;
		sum+=tmp;
		k/=10;
	}
	for (int i=0;i<=50;i++)
		if (sum==f[i]) return 1;
	return 0;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	init();
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=min(n,m);i<=max(n,m);i++)
		if (check(i)) printf("%d ",i);
}

