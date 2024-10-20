#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int d[100005],a[100005],dd[100005];

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
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int cmp(const void *a,const void *b)
{
	int *x=(int *)a;
	int *y=(int *)b;
	return *x-*y;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,check=0,res[100005],nmax=0,Max=-1;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) 
		{
			d[i]=0;
			dd[i]=0;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			d[a[i]]++;
		}
		for (int i=1;i<=n;i++)
			if (d[a[i]])
			{
				dd[a[i]]=d[a[i]];
				if (d[a[i]]>Max && gcd(d[a[i]],a[i])==1) 
				{
					check=1;
					Max=d[a[i]];
					nmax=0;
					res[++nmax]=a[i];
				}
				else 
					if (d[a[i]]==Max && gcd(d[a[i]],a[i])==1) 
						{
							check=1;
							res[++nmax]=a[i];
						}
				d[a[i]]=0;
			}
		if (!check) printf("None!\n");
		else 
		{
			qsort(res+1,nmax,sizeof(res[1]),cmp);
			for (int i=1;i<=nmax;i++) printf("%d %d\n",res[i],dd[res[i]]);
		}
	}
}

