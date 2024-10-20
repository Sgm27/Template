#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n;
char a[1005][1005],tmp[1005];

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
void process()
{
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
		{
			char tmp1[1005]="",tmp2[1005]="";
			strcpy(tmp1,a[i]);
			strcpy(tmp2,a[j]);
			strcat(tmp1,a[j]);
			strcat(tmp2,a[i]);
			if (strcmp(tmp1,tmp2)>=0) 
			{
				char tmpx[1005];
				strcpy(tmpx,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],tmpx);
			}
		}
	for (int i=1;i<=n;i++) printf("%s",a[i]);
	printf("\n");
}

int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%s",tmp);
			strcpy(a[i],tmp);
		}
		process();
	}
}

