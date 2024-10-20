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
	int n;
	scanf("%d",&n);
	int m=2*n-1,cs=n,l=1,r=2*n-1;
	for (int i=1;i<=n;i++)
	{
		
		for (int j=n;j>=cs;j--) printf("%d",j);
		for (int j=l+1;j<r;j++) printf("%d",cs);
		if (cs!=1) 
			for (int j=cs;j<=n;j++) printf("%d",j);
		else 
			for (int j=cs+1;j<=n;j++) printf("%d",j);
		l++;
		r--;
		cs--; 
		printf("\n");
	}
	l=n-1,r=n+1;
	cs=2;
	for (int i=1;i<n;i++)
	{
		for (int j=n;j>=cs;j--) printf("%d",j);
		for (int j=l+1;j<r;j++) printf("%d",cs);
		for (int j=cs;j<=n;j++) printf("%d",j);
		l--;
		r++;
		cs++;
		printf("\n");
	}
}

