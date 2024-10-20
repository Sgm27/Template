#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
//	freopen("thu.inp","r",stdin);
	int n,m,cnt;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int cnt=i;
		if (cnt<m)
		{
			int tmp=m-cnt+1,x=cnt,k=tmp;
			while (tmp)
			{
				printf("%d",x++);
				tmp--;
			}
			tmp=m-k;
			x=m-1;
			while (tmp)
			{
				printf("%d",x--);
				tmp--;
			}
		}
		else 
		{
			for (int i=1;i<=m;i++) printf("%d",cnt-i+1);
		}
		printf("\n");
	}
}

