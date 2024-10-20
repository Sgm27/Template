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
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int l,r,cnt=0;
		scanf("%d %d",&l,&r);
		for (int i=l;i<=r;i++)
		{
			int check=1;
			if (i<2) continue;
			for (int j=2;j<=sqrt(i);j++)
			if (i%j==0)
			{
				check=0;
				break;
			}
			if (check) cnt++;
		}
		printf("%d\n",cnt);
	}
}

