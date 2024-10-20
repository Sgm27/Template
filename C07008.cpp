#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char dt1[10005][105],dt2[10005][105];
int res[10005],n,m;
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
int mu(char s[105])
{
	int res=0,k=1;
	for (int i=strlen(s)-1;i>=0;i--)
		if (s[i]!='^') 
		{
			res+=(s[i]-'0')*k;
			k*=10;
		}
		else return res;
}
int heso(char s[105])
{
	int res=0;
	for (int i=0;i<strlen(s);i++) 
		if (isdigit(s[i]))
		{
			res=res*10+(s[i]-'0');
		}
		else return res;
}
void reset()
{
	n=0; 
	m=0;
	char tmp[105]="";
	for (int i=0;i<=10005;i++) res[i]=0;
	for (int i=1;i<=1000;i++) 
	{
		strcpy(dt1[i],tmp);
		strcpy(dt2[i],tmp);
	}
}
void process()
{
	int Max=-1,Min=1e7;
	for (int i=1;i<=n;i++) 
	{
		Max=max(Max,mu(dt1[i]));
		Min=min(Min,mu(dt1[i]));
		res[mu(dt1[i])]+=heso(dt1[i]);
	}
	for (int i=1;i<=m;i++) 
	{
		Max=max(Max,mu(dt2[i]));
		Min=min(Min,mu(dt2[i]));
		res[mu(dt2[i])]+=heso(dt2[i]);
	}
	for (int i=Max;i>Min;i--)
		if (res[i]) 
			printf("%d*x^%d + ",res[i],i);
	printf("%d*x^%d\n",res[Min],Min);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	getchar();
	while (tc--)
	{
		char tmp1[10000],tmp2[10000];
		reset();
		gets(tmp1); 
		gets(tmp2);
		char *token=strtok(tmp1," ");
		while (token!=NULL)
		{
			if (strlen(token)!=1) strcpy(dt1[++n],token);
			token=strtok(NULL," ");
		}
		char *tokin=strtok(tmp2," ");
		while (tokin!=NULL)
		{
			if (strlen(tokin)!=1) strcpy(dt2[++m],tokin);
			tokin=strtok(NULL," ");
		}
		process();
	}
}

