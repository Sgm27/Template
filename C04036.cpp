#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int a[10]={1,2,5,10,20,50,100,200,500,1000};
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
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,i=9,cnt=0;
		scanf("%d",&n);
		while (n)
		{
			if (n<a[i]) i--;
			else 
			{
				cnt++;
				n-=a[i];
			}
		}
		printf("%d\n",cnt);
	}
}

