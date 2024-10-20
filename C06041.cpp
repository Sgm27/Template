#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	//freopen("thu.inp","r",stdin);
	char s[100005],res[100005];
	scanf("%s",&s);
	res[strlen(s)-1]=s[strlen(s)-1];
	for (int i=strlen(s)-2;i>=0;i--) 
	{
		if (s[i]>res[i+1]) res[i]=s[i];
		else res[i]=res[i+1];
	}
	for (int i=0;i<strlen(s);i++) 
		if (s[i]==res[i]) printf("%c",res[i]);
}

