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
void cmp(char a[],char b[])
{
	if (strlen(a)!=strlen(b))
	{
		if (strlen(a)<strlen(b)) 
		{
			char tmp[10005];
			strcpy(tmp,a);
			strcpy(a,b);
			strcpy(b,tmp);
		}
		return;
	}
	if (strcmp(a,b)<0)
	{
		char tmp[10005];
		strcpy(tmp,a);
		strcpy(a,b);
		strcpy(b,tmp);
		return;
	}
}
void hieu(char a[],char b[])
{
	char res[10005];
	if (strcmp(a,b)==0) 
	{
		printf("0\n");
		return;
	}
	cmp(a,b);
	while (strlen(b)!=strlen(a))
	{
		char tmp[10005]="0";
		strcat(tmp,b);
		strcpy(b,tmp);
	}
	int nho=0;
	for (int i=strlen(b)-1;i>=0;i--)
	{
		int tmp=(a[i]-'0')-(b[i]-'0')-nho;
		if (tmp<0)
		{
			tmp+=10;
			nho=1;
		}
		else nho=0;
		res[i]=tmp+'0';
	}
	int k=0;
	while (res[k]=='0') k++;
	for (int i=k;i<strlen(res);i++) printf("%c",res[i]);
	printf("\n");
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		char a[10005],b[10005];
		scanf("%s %s",a,b);
		hieu(a,b);
	}
}

