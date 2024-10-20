#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s1[1005],s2[1005],a[1005][1005],tmp[1005][1005];
int n,m,d[10005];
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
void process()
{
	memset(d,0,sizeof(d));
	for (int i=1;i<=n;i++) strcpy(tmp[i],a[i]);
	for (int i=1;i<=n;i++) to_lower(tmp[i]);
	for (int i=1;i<=n;i++) 
	{
		if (strcmp(tmp[i],s2)!=0) d[i]=1;
	}
	for (int i=1;i<=n;i++)
		if (d[i]) printf("%s ",a[i]);
	printf("\n");
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	getchar();
	for (int stt=1;stt<=tc;stt++)
	{
		printf("Test %d: ",stt);
		gets(s1); 
		gets(s2);
		to_lower(s2);
		m=0; n=0;
		char *token=strtok(s1," ");
		while (token!=NULL)
		{
			strcpy(a[++n],token);
			token=strtok(NULL," ");
		}
		process();
	}
}

