#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char a[105][105],tmp[105],s[105][1005];
int n;
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
void sinhhoanvi()
{
	for (int k=0;k<strlen(tmp);k++)
	{
		char tmp1[100]="",tmp2[100]="";
		strncpy(tmp1,tmp,k);
		strncpy(tmp2,tmp+k,strlen(tmp)-k);
		strcat(tmp2,tmp1);
		strcpy(s[k],tmp2);
	}
}
int check()
{
	for (int i=1;i<=n;i++)
	{
		int kt=0;
		for (int j=0;j<strlen(tmp);j++) 
			if (strcmp(a[i],s[j])==0)
			{
				kt=1;
				break;
			}
		if (kt==0) return 0;
	}
	return 1;
}
void process()
{
	int res=1e9;
	if (!check()) 
	{
		printf("-1");
		return;
	}
	for (int i=0;i<strlen(tmp);i++)
	{
		// chon s[i] lam moc so sanh
		int cnt=0;
		for (int j=1;j<=n;j++) 
			if (strcmp(s[i],a[j])!=0)
			{
				for (int k=0;k<strlen(a[j]);k++) 
				{
					char tmp1[100]="",tmp2[100]="";
					strncpy(tmp1,a[j],k);
					strncpy(tmp2,a[j]+k,strlen(a[j])-k);
					strcat(tmp2,tmp1);
					if (strcmp(tmp2,s[i])==0) 
					{
						cnt+=k;
						break;
					}
				}
			}
		res=min(res,cnt);
	}
	printf("%d",res);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%s",tmp);
		strcpy(a[i],tmp);
	}
	sinhhoanvi();
	process();
}

