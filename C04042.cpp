#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
const int Max=1e9;

int gt[100005],cs[100005],n;
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
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void sort(int l,int r)
{
	int i=l,j=r,g=gt[(int)((i+j)/2)];
	while (i<=j)
	{
		while (gt[i]<g) i++;
		while (gt[j]>g) j--;
		if (i<=j)
		{
			swap(&gt[i],&gt[j]);
			swap(&cs[i],&cs[j]);
			i++;
			j--;
		}
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r); 
}
void process()
{
	sort(1,n);
	int min_pos=Max,check=0,res;
	gt[n+1]=-1;
	for (int i=1;i<=n;i++)
	{
		if (gt[i]==gt[i+1] && min(cs[i],cs[i+1])<min_pos)
		{
			check=1;
			res=gt[i];
			min_pos=min(cs[i],cs[i+1]);
		}
	}
	if (!check)
		printf("NO\n");
	else printf("%d\n",res);
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) 
		{
			scanf("%d",&gt[i]);
			cs[i]=i;
		}
		process();
	}
}

