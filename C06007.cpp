#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
char s[10005],tmp[1005],a[1005][1005],n=0;

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
	gets(s);
	char *token=strtok(s," ");
	while (token!=NULL)
	{
		strcpy(a[++n],token);
		token=strtok(NULL," ");
	}
	scanf("%s",tmp);
	for (int i=1;i<=n;i++) 
	{
		if (strcmp(a[i],tmp)!=0) printf("%s ",a[i]);
	}
}

