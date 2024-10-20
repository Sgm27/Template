#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N=1e7;
int prime[10000005],pri[1000005],cnt=0;
void sang()
{
	for (int i=1;i<=N;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=1;i<=sqrt(N);i++)
		if (prime[i]) 
		{
			pri[++cnt]=i;
			for (int j=i*i;j<=N;j+=i) prime[j]=0;
		}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	sang();
	int tc;
	scanf("%d",&tc);
	for (int k=1;k<=tc;k++)
	{
		printf("Test %d:\n",k);
		int a[100][100],i,j,hang,cot,n,d,gt,x,y;
		scanf("%d",&n);
		gt=1;
		hang=n-1; cot=n-1;d=0;
		while(d<=n/2)
		{
			for (i=d;i<=cot;i++) a[d][i]=pri[gt++];
			for (i=d+1;i<=hang;i++) a[i][cot]=pri[gt++];
			for (i=cot-1;i>=d;i--) a[hang][i]=pri[gt++];
			for (i=hang-1;i>d;i--) a[i][d]=pri[gt++];
			d++;hang--;cot--;
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
} 
