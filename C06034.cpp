#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s[1005];
int val(char x)
{
	if (x=='I') return 1;
	if (x=='V') return 5;
	if (x=='X') return 10;
	if (x=='L') return 50;
	if (x=='C') return 100;
	if (x=='D') return 500;
	if (x=='M') return 1000;
}
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
	long long res=0;
	for (int i=strlen(s)-2;i>=0;i--)
	{
		if (val(s[i])>=val(s[i+1])) res+=val(s[i]);
		else res-=val(s[i]);
	//	printf("%lld\n",res);
	}
	res+=val(s[strlen(s)-1]);
	printf("%lld\n",res);
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%s",s);
		process();
	}
}

