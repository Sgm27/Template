#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int d[1005];

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
int cmp(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
int nto(int k)
{
	if (k==2 || k==3) return 1;
	if (k<2 || k%2==0 || k%3==0) return 0;
	int i=5;
	while (i<=(int)(sqrt(k)))
	{
		if (k%i==0 || k%(i+2)==0) return 0;
		else i+=6;
	}
	return 1;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	for (int stt=1;stt<=tc;stt++)
	{
		printf("Test %d:\n",stt);
		memset(d,1,sizeof(d));
		int n,a[1005];
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		qsort(a+1,n,sizeof(int),cmp);
		for (int i=1;i<=n;i++)
			if (d[i] && nto(a[i]))
			{
				int cnt=0;
				for (int j=i;j<=n;j++) 
					if (a[i]==a[j])
					{
						cnt++;
						d[j]=0;
					}
				printf("%d xuat hien %d lan\n",a[i],cnt);
			}
	}
}

