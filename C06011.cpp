#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;


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
	int sum=0;
	for (int i=0;i<strlen(s);i++) sum+=(s[i]-'0');
	if (sum%10) return 0;
	int l=0,r=strlen(s)-1;
	if (s[l]!='8' || s[r]!='8') return 0;
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
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		char s[1005];
		scanf("%s",s);
		if (check(s)) printf("YES\n");
		else printf("NO\n");
	}
}
