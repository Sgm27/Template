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
int cd(int k)
{
	if (k==1) return 1;
	return 0;
}
void  process(ll n)
{
	int res[100],nmax=0;
	res[0]=27;
	while (n)
	{
		int tmp=n%10;
		if (tmp!=0 && tmp!=1 && tmp!=8 && tmp!=9) 
		{
			printf("INVALID\n");
			return;
		}
		res[++nmax]=cd(tmp);
		n/=10;
	}
	int k=nmax;
	while (res[k]==0) k--;
	if (k==0) 
	{
		printf("INVALID\n");
		return;
	}
	for (int i=k;i>=1;i--) printf("%d",res[i]);
	printf("\n");
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		long long n;
		scanf("%lld",&n);
		process(n);
	}
}


