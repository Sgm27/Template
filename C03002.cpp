#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
const int N=1000005;
int prime[1000005];
void sang()
{
	for (int i=1;i<=N;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=2;i<=sqrt(N);i++)
		if (prime[i])
			for (int j=i*i;j<=N;j+=i) prime[j]=0;
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
int main()
{
	//freopen("thu.inp","r",stdin);
	sang();
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		if (prime[i]) printf("%d\n",i);
}

