#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
		printf("1");
	}
	printf("%s\n",res);
}


int main()
{
//	freopen("thu.inp","r",stdin);
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		char a[1005],b[1005];
		scanf("%s %s",a,b);
		cong(a,b);
	}
}

