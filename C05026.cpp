#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int N=1e7;
int prime[10000005],n,a[1005][1005];
void sang()
{
	for (int i=1;i<=N;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=1;i<=sqrt(N);i++)
		if (prime[i]) 
		{
			for (int j=i*i;j<=N;j+=i) prime[j]=0;
		}
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
	sang();
//	freopen("thu.inp","r",stdin);
	scanf("%d",&n);
	int Max=-1,cs;
	for (int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		for (int j=1;j<=n;j++)	
			if (prime[a[i][j]]) cnt++;
		if (cnt>Max) 
		{
			Max=cnt;
			cs=i;
		}
	}
	printf("%d\n",cs);
	for (int i=1;i<=n;i++)
		if (prime[a[cs][i]]) printf("%d ",a[cs][i]);
}

