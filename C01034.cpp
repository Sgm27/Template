#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int a[1000005];
int cp(int k)
{
	int tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
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
	//freopen("thu.inp","r",stdin);
	int m,n,l,r,k=0;
	scanf("%d %d",&m,&n);
	if (cp(m)) l=(int)(sqrt(m));
	else l=(int)(sqrt(m))+1; 
	r=sqrt(n);
	for (int i=l;i<=r;i++) a[++k]=i*i;
	printf("%d\n",k);
	for (int i=1;i<=k;i++) printf("%d\n",a[i]);
}

