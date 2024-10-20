#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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
	int tc,n;
	scanf("%d",&tc);
	for (int stt=1;stt<=tc;stt++)
	{
		int a[1500],b[1500],dem=0;
		scanf("%d",&n);
		printf("%d = ",n);
		int i=2;
		while (n!=1)
		{
			int cnt=0;
			while (n%i==0) 
			{
				cnt++;
				n/=i;
			}
			if (cnt!=0) 
			{
				dem++;
				a[dem]=i;
				b[dem]=cnt;
			}
			i++;
		}
		printf("%d^%d ",a[1],b[1]);
		for (int i=2;i<=dem-1;i++) 
			printf("* %d^%d ",a[i],b[i]);
		if (dem!=1) printf("* %d^%d",a[dem],b[dem]);
		printf("\n");
	}
}


