#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char tmp_ts[100],res_nhan[100];

void to_string(int n)
{
	sprintf(tmp_ts,"%d",n);
	tmp_ts[strlen(tmp_ts)]='\0';
}
void nhan(char s[],int n)
{
	int i=0;
	while (s[i]=='0') i++;
	int cnt_zero=i;
	char res[100]="";
	int nho=0;
	for (int i=strlen(s)-1;i>=cnt_zero;i--)
	{
		int tmp=(s[i]-'0')*n+nho;
		nho=tmp/10;
		tmp%=10;
		to_string(tmp); //tmp_ts
		strcat(tmp_ts,res);
		strcpy(res,tmp_ts);
	}
	if (nho != 0) 
	{
		char tmp[100];
		to_string(nho); //tmp_ts
		strcpy(tmp,tmp_ts);
		strcat(tmp,res);
		strcpy(res,tmp);
	}
	for (int i=strlen(res)+1;i<=strlen(s);i++)
	{
		char tmp[100]="0";
		strcat(tmp,res);
		strcpy(res,tmp);
	}
	strcpy(res_nhan,res);
	res_nhan[strlen(res_nhan)]='\0';
}

int process(char s[])
{
	for (int i=2;i<=strlen(s);i++)
	{
		int check=0;
		nhan(s,i); //res_nhan
		char tmp[100];
		strcpy(tmp,res_nhan);
		tmp[strlen(tmp)]='\0';
		for (int k=0;k<strlen(tmp);k++)
		{
			char tmp1[100]="",tmp2[100]="";
			strncpy(tmp1,tmp,k);
			strncpy(tmp2,tmp+k,strlen(tmp)-k);
			strcat(tmp2,tmp1);
			if (strcmp(tmp2,s)==0)
			{
				check=1;
				break;
			}
		}
		if (!check) return 0;
	}
	return 1;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		char s[100];
		scanf("%s",&s);
		if (process(s)) printf("YES\n");
		else printf("NO\n");
	}
}
