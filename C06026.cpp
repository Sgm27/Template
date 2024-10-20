#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
string
char a[1005][1005];
int n=0,d[1005],Max=-1;
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
int check_tn(char s[])
{
	int l=0,r=strlen(s)-1;
	while (l<r)
	{
		if (s[l]!=s[r]) return 0;
		l++;
		r--;
	}
	return 1;
}
int main()
{
	freopen("thu.inp","r",stdin);
	char s[1005];
	while (scanf("%s",s)!=-1) 
	{
		if (check_tn(s))
		{
			Max=max(Max,strlen(s));
			int check=1;
			for (int i=1;i<=n;i++)	
				if (strcmp(a[i],s)==0)
				{
					d[i]++;
					check=0;
					break;
				}
			if (check) 
			{
				strcpy(a[++n],s);
				d[n]=1;
			}
		}
	}
	for (int i=1;i<=n;i++)
		if (strlen(a[i])==Max) printf("%s %d\n",a[i],d[i]);
}


