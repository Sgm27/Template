#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
char s[10005],a[1005][1005],n=0;
int d[10005];
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
	memset(d,1,sizeof(d));
//	freopen("thu.inp","r",stdin);
	gets(s);
	char *token=strtok(s," ");
	while (token != NULL)
	{
		strcpy(a[++n],token);
		token=strtok(NULL," ");
	}
	for (int i=1;i<=n;i++)
		if (d[i])
		{
			printf("%s ",a[i]);
			for (int j=i;j<=n;j++) 
				if (strcmp(a[i],a[j])==0) d[j]=0;
		}
}

