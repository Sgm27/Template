#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n;
char s1[1005],s2[1005],s[1005];
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


int main()
{
	//freopen("thu.inp","r",stdin);
	while (scanf("%d",&n)!=-1)
	{
		char stmp[1005]="",x;
		if (!n) return 0;
		scanf("%s %s %s",s1,s2,s);
		int check=1,cnt=0,kt;
		
		while (check)
		{
			cnt++;
			if (cnt>=270) check=0;
			int l1=0,l2=0;
			for (int i=0;i<2*n;i++) 
			{
				if (i%2==0) stmp[i]=s2[l2++];
				else stmp[i]=s1[l1++];
			}
			kt=1;
			for (int i=0;i<2*n;i++) 
				if (stmp[i]!=s[i]) 
				{
					kt=0;
					break;
				}
			if (kt==1) break;
			else
				for (int i=0;i<n;i++)
				{
					s1[i]=stmp[i];
					s2[i]=stmp[i+n];
				}
		}
		if (!kt) printf("-1\n");
		else printf("%d\n",cnt);
	}
}

