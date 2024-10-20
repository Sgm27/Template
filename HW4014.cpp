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
void to_lower(char s[])
{
	for (int i=0;i<strlen(s);i++)
		if (s[i]>='A' && s[i]<='Z') s[i]=(char)((int)(s[i])+32);
}
void process(char s[])
{
	char a[150][150];
	int n=0;
	char *token=strtok(s," ");
	while (token!=NULL)
	{
		strcpy(a[++n],token);
		token=strtok(NULL," ");
	}
    printf("%s",a[n]);
	for (int i=1;i<=n;i++)
		if (i!=n) printf("%c",a[i][0]);
		else printf("@itptit.edu.vn");
    printf("\n");
}
int main()
{
	// freopen("thu.inp","r",stdin);
	int tc;
    scanf("%d",&tc);
    getchar();
    while (tc--)
    {
        char s[150];
        gets(s);
        to_lower(s);
        process(s);
    }
}

