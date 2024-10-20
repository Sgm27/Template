#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
char tmp_plus[1005];
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
        char t[1005]="1";
        strcat(t,res);
        strcpy(res,t);
    }
	strcpy(tmp_plus,res);
}
void process(char s[])
{
    ll nmax=0;
    char a[1005][10];
    char res[1005]="0";

    for (int i=0;i<strlen(s);i++) 
    if (s[i]>='0' && s[i]<='9') a[++nmax][0]=s[i];
    if (nmax==0) 
    {
        printf("0\n");
        return;
    }
    for (int i=1;i<=nmax;i++)
    {
        char sum[1005]="";
        for (int j=i;j<=nmax;j++) 
        {
            strcat(sum,a[j]);
            cong(sum,res);
            strcpy(res,tmp_plus);
        }
    }
    int it=0;
    while (res[it]=='0') it++;
    for (int i=it;i<strlen(res);i++) printf("%c",res[i]);
    printf("\n");
}
int main()
{
    // freopen("thu.inp","r",stdin);
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        char s[1005];
        scanf("%s",s);
        process(s);
    }
}
