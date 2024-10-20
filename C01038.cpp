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
void process(int n)
{
	char tmp[150];
	sprintf(tmp,"%d",n);
	char x=tmp[0];
	tmp[0]=tmp[strlen(tmp)-1];
	tmp[strlen(tmp)-1]=x;
	int i=0;
	while (tmp[i]=='0') i++;
	for (int j=i;j<strlen(tmp);j++) printf("%c",tmp[j]);
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int n;
	scanf("%d",&n);
	process(n);
}

