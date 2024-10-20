#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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
int check(char s[])
{
	int l=0,r=strlen(s)-1,cnt=0;
	while (l<r)
	{
		if (s[l]!=s[r]) cnt++;
		l++;
		r--;
	}
	return cnt;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		char s[1005];
		scanf("%s",s);
		if ((check(s)==1) || (check(s)==0 && strlen(s)%2)) printf("YES\n");
		else printf("NO\n");
	}
}

