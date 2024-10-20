#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
char res_sum[1005];

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
void cong(char a[],char b[])
{
	char res[1005]="";
	while (strlen(a)<strlen(b)) 
	{
		char tmp[1005]="0";
		strcat(tmp,a);
		strcpy(a,tmp);
	}
	while (strlen(b)<strlen(a)) 
	{
		char tmp[1005]="0";
		strcat(tmp,b);
		strcpy(b,tmp);
	}
	
	int nho=0;
	for (int i=strlen(a)-1;i>=0;i--)
	{
		int tmp=(a[i]-'0')+(b[i]-'0')+nho;
		if (tmp>=10) nho=1;
		else nho=0;
		tmp%=10;
		char x[1005]="";
		x[0]=(char)(tmp+'0');
		strcat(x,res);
		strcpy(res,x);
	}
	if (nho) 
	{
		char tmp[1005]="1";
		strcat(tmp,res);
		strcpy(res,tmp);
	}
	strcpy(res_sum,res);
}
void process(char s[])
{
	if (strlen(s)==1) 
	{
		printf("%s",s);
		return;
	}
	while (strlen(s)>1)
	{
		int k=strlen(s)/2;
		char tmp1[1005]="",tmp2[1005]="";
		strncpy(tmp1,s,k);
		strncpy(tmp2,s+k,strlen(s)-k);
		cong(tmp1,tmp2); // res_sum;
		strcpy(s,res_sum);
		printf("%s\n",s);
	}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	char s[1005];
	scanf("%s",s);
	process(s);
}

