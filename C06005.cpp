#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char tmp[100005];
char a[1005][1005];
int n=0,d[1005];
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

int main()
{
	memset(d,1,sizeof(d));
//	freopen("thu.inp","r",stdin);
	gets(tmp);
	to_lower(tmp);
	char *token=strtok(tmp," ");
	while (token!=NULL)
	{
		strcpy(a[++n],token);
		token=strtok(NULL," ");
	}
	for (int i=1;i<=n;i++)
		if (d[i])
		{
			d[i]=0;
			int cnt=0;
			for (int j=i;j<=n;j++) 
				if (strcmp(a[i],a[j])==0) 
				{
					cnt++;
					d[j]=0;
				}
			printf("%s %d\n",a[i],cnt);
		}
}

