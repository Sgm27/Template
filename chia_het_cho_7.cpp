#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
char res_plus[1005];

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
void rev(char a[]) {
	int l=0, r=strlen(a)-1;
	while(l<r) {
		char tmp=a[l];
		a[l]=a[r];
		a[r]=tmp;
		l++;
		r--;
	}
}
int bigmod(char s[])
{
	int res=0;
	for (int i=0;i<strlen(s);i++)
	{
		res=(res*10+(s[i]-'0'))%7;
	}
	return res==0;
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
	char tmp[1005]="";
	if (nho)
	{
		strcpy(tmp,"1");
	}
	strcat(tmp,res);
	strcpy(res_plus,tmp);
}

int main()
{
	// freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		char s1[1005]="";
		int stt=0,check=0;
		scanf("%s",s1);
		if (bigmod(s1)) 
		{
			printf("%s\n",s1);
			continue;
		}
		while (++stt<1000)
		{
			char tmp[1005]="",s2[1005]="";
			strcpy(tmp,s1);
			rev(tmp);
			strcpy(s2,tmp);
			cong(s1,s2); // res_plus
			if (bigmod(res_plus)) 
			{
				printf("%s\n",res_plus);
				check=1;
				break;
			}
			else strcpy(s1,res_plus);
		}
		if (!check) printf("-1\n");
	}
}

