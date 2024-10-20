#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n=0,d[1005];
char a[1005][1005];

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
void process()
{
	int Max=-1;
	for (int i=1;i<=n;i++) d[i]=1;
	for (int i=1;i<=n;i++) Max=max(Max,strlen(a[i]));
	for (int i=1;i<=n;i++)
	{
		if (strlen(a[i])==Max && d[i])
		{
			int cnt=0;
			for (int j=i;j<=n;j++)
				if (strcmp(a[i],a[j])==0) 
				{
					d[j]=0;
					cnt++;
				}
			printf("%s %d %d\n",a[i],Max,cnt);
		}
	}
}

int main()
{
//	freopen("thu.inp","r",stdin);
	char s[10005];
	while (scanf("%s",s)!=-1)
	{
		strcpy(a[++n],s);
	}
	process();
}


