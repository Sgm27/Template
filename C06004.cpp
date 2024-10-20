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


int main()
{
//	freopen("thu.inp","r",stdin);
	int chu=0,so=0;
	char s[10005];
	gets(s);
	for (int i=0;i<strlen(s);i++) 
	{
		if (s[i]>='0' && s[i]<='9') so++;
		else 
		if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) chu++;
	}
	printf("%d %d %d",chu,so,strlen(s)-chu-so);
}

