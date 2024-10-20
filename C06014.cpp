#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void to_lower(char s[])
{
	for (int i=0;i<strlen(s);i++)
		if (s[i]>='A' && s[i]<='Z') s[i]=(char)((int)(s[i])+32);
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
void chuanhoa(char c[]) 
{ 
 	if (c[0]>='a' && c[0]<='z') c[0]=c[0]-32; 
	for (int i=1;i<strlen(c);i++) 
		if (c[i]>='A' && c[i]<='Z') c[i]=c[i]+32; 
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc,n;
	scanf("%d",&tc);
	getchar();
	while (tc--)
	{
		n=0;
		char s[1500],a[150][150];
		gets(s);
		char *token=strtok(s," ");
		while (token!=NULL)
		{
			strcpy(a[++n],token);
			token=strtok(NULL," ");
		}
		for (int i=1;i<=n;i++)
		{
			chuanhoa(a[i]);
			printf("%s",a[i]);
			if (i!=n) printf(" ");
		}
		printf("\n");
	}
}

