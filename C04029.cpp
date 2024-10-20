#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n,a[105],b[105];


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
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int cnt=1,stt=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n-cnt;j++) 
			if (a[j]>a[j+1])
			{
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		cnt++;
		int check=0;
		for (int i=1;i<=n;i++)
			if (a[i]!=b[i])
			{
				check=1;
				break;
			}
		if (check) 
		{	
			stt++;
			printf("Buoc %d: ",stt);
			for (int i=1;i<=n;i++) 
			{
				printf("%d ",a[i]);
				b[i]=a[i];
			}
			printf("\n");
		}
	}
}

