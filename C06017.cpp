#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s1[1005],s2[1005],a[105][105],b[105][105],res[105][105];
int n=0,m=0,cnt;

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
int cmp(const void *a,const void *b)
{
	char *x=(char*)a;
	char *y=(char*)b;
	if (strcmp(x,y)<0) return -1;
	else return 1;
}
void process()
{
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		int check=1;
		for (int j=1;j<=m;j++)
			if (strcmp(a[i],b[j])==0) 
			{
				check=0;
				break;
			}
		if (check) strcpy(res[++cnt],a[i]);
	}
	qsort(res+1,cnt,sizeof(res[1]),cmp);
	strcpy(res[0],"ducson");
	for (int i=1;i<=cnt;i++)
		if (strcmp(res[i],res[i-1])!=0) printf("%s ",res[i]);
}
int main()
{
	//freopen("thu.inp","r",stdin);
	gets(s1); 
	gets(s2);
	char *token=strtok(s1," ");
	while (token!=NULL)
	{
		strcpy(a[++n],token);
		token=strtok(NULL," ");
	}
	char *tokin=strtok(s2," ");
	while (tokin!=NULL)
	{
		strcpy(b[++m],tokin);
		tokin=strtok(NULL," ");
	}
	process();
}

