#include <stdio.h>
#include <stdlib.h>
int n,k;
int main()
{
	scanf("%d %d",&n,&k);
	int a[1005],nmax=0;
	while (n)
	{
		a[++nmax]=n%k;
		n/=k;
	}
	for (int i=nmax;i>=1;i--)
		if (a[i]>=10) printf("%c",a[i]+55); else printf("%d",a[i]);
}
