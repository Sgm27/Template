#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int n,h,k;
char a[15][10005];
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
int doi(char c)
{
	if (isdigit(c)) return c-'0';
	if (c=='A') return 10;
	else return c-'A'+10; 
}
void process()
{
	ll tmp=0;
	for (int i=0;i<strlen(a[1]);i++) tmp=tmp*16+doi(a[1][i]);
	int base=atoll(a[3]);
	int nmax=0,ans[10005];
	while (tmp)
	{
		ans[++nmax]=tmp%base;
		tmp/=base;
	}
	for (int i=nmax;i>=1;i--) 	
		if (ans[i]>=10) 
			printf("%c",ans[i]-10+'A');
		else printf("%d",ans[i]);
}
void process1()
{
	ll tmp=0;
	ll base=atoll(a[3]);
	ll base1=atoll(a[2]);
	for (int i=0;i<strlen(a[1]);i++)
	{
		tmp=tmp*base1+(a[1][i]-'0');
	}
	int nmax=0,ans[10005];
	while (tmp)
	{
		ans[++nmax]=tmp%base;
		tmp/=base;
	}
	for (int i=nmax;i>=1;i--) 	
		if (ans[i]>=10) 
			printf("%c",ans[i]-10+'A');
		else printf("%d",ans[i]);
}
int main()
{
	// freopen("thu.inp","r",stdin);
	int tc; scanf("%d",&tc);
	getchar();
	while (tc--)
	{
		char s[10005];
		gets(s);
		n=0;
		char *token=strtok(s," ");
		while (token!=NULL)
		{
			strcpy(a[++n],token);
			token=strtok(NULL," ");
		}
		int flag=1;
		for (int i=0;i<strlen(a[1]);i++)
			if (!isdigit(a[1][i])) 
			{
				flag=0;
				break;
			}
		if (!flag) 
		{
			process();
		}
		else process1();
		printf("\n");
	}
}

