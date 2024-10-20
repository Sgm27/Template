#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct mang{
	int mau,hang,cot;
};
int n,m,nmax;
struct mang a[1005*1005];
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
int check(struct mang tmp1,struct mang tmp2,struct mang tmp3)
{
	if (tmp1.mau==tmp3.mau && tmp1.mau!=tmp2.mau && tmp1.hang==tmp2.hang && tmp2.cot==tmp3.cot) return 1;
	return 0;
}
void process()
{
	int res=0;
//	for (int i=1;i<=nmax;i++) 
//		printf("%d %d %d\n",a[i].mau,a[i].hang,a[i].cot);
	for (int i=1;i<=nmax-2;i++)
		for (int j=i+1;j<=nmax-1;j++)
			for (int k=j+1;k<=nmax;k++) 
				if (check(a[i],a[j],a[k]) || check(a[i],a[k],a[j]) || check(a[j],a[i],a[k]) || check(a[j],a[k],a[i]) || check(a[k],a[i],a[j]) || check(a[k],a[j],a[i])) 
				{
					res++;
				//	printf("%d %d %d\n",i,j,k);
				}
	printf("%d\n",res);
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; 
	scanf("%d",&tc);
	while (tc--)
	{
		nmax=0;
		scanf("%d %d",&n,&m);
		char x;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				scanf(" %c",&x);
				if (x!='0') 
				{
					nmax++;
					a[nmax].mau=x-'0';
					a[nmax].hang=i;
					a[nmax].cot=j;
				}
			}
		process();
	}
	
}


