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
	int n,x,y,Max=-1,sum=0,cnt;
	char res[1005];
	scanf("%d",&n);
	while (n--)
	{
		cnt=0;
		char s[1005];
		scanf("%s %d %d",s,&x,&y);
		while (y>=x)
		{
			int tmp=y/x;
			cnt+=tmp;
			y-=tmp*x;
			y+=tmp*2;
		}
		if (cnt>Max)
		{
			Max=cnt;
			strcpy(res,s);
		}
		sum+=cnt;
	}
	printf("%d\n%s",sum,res);
}

