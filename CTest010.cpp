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
		char s[1005];
		int d[256];
		memset(d,0,sizeof(d));
		scanf("%s",s);
		for (int i=0;i<strlen(s);i++) d[(int)(s[i])]++;
		for (int i=0;i<strlen(s);i++)
			if (d[(int)(s[i])])
			{
				printf("%c%d",s[i],d[(int)(s[i])]);
				d[(int)(s[i])]=0;
			}
		printf("\n");
	}
}

