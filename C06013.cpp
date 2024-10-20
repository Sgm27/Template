#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s[100005];

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
void process(char s[])
{
	int dl=0,dc=0;
	if (s[0]=='0') 
	{
		printf("INVALID\n");
		return;
	}
	for (int i=0;i<strlen(s);i++) 
		if (s[i]>='0' && s[i]<='9') 
		{
			if ((s[i]-'0')%2) dl++;
			else dc++;
		}
		else 
		{
			printf("INVALID\n");
			return;
		}
	int n=strlen(s);
	if ((n%2 && dl>dc) || (n%2==0 && dc>dl) ) printf("YES\n");
	else printf("NO\n");
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%s",s);
		process(s);
	}
}

