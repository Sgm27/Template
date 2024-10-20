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
int tang(char s[])
{
	for (int i=1;i<strlen(s);i++)
		if (s[i]<=s[i-1]) return 0;
	return 1;
}
int bang(char s[])
{
	for (int i=0;i<strlen(s)-1;i++)
		if (s[i]!=s[i+1]) return 0;
	return 1;
}
int haiba(char s[])
{
	for (int i=0;i<2;i++) 
		if (s[i]!=s[i+1]) return 0;
	if (s[3]!=s[4]) return 0;
	return 1;
}
int locphat(char s[])
{
	for (int i=0;i<strlen(s);i++) 
		if (s[i]!='6' && s[i]!='8') return 0;
	return 1;
}
int check(char s[])
{
	if (tang(s) || bang(s) || haiba(s) || locphat(s)) return 1;
	return 0;
}

int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		char s1[105]="",s2[105]="",s[105];
		scanf("%s",s);
		scanf("%s",s);
		strncpy(s1,s,3);
		strncpy(s2,s+4,2);
		strcpy(s,strcat(s1,s2));
		//printf("%s\n",s);
		if (check(s)) printf("YES\n");
		else printf("NO\n");
	}
}

