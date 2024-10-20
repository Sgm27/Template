#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s[55];
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
	int dp[55],n=strlen(s),Max=-1;	
	for (int i=0;i<n;i++)
	{
		dp[i]=1;
		for (int j=0;j<i;j++) 
			if ((int)(s[i])>(int)(s[j])) dp[i]=max(dp[i],dp[j]+1);
		Max=max(Max,dp[i]);
	}
	printf("%d",26-Max);
}
// dynamic programing LIS
int main()
{
//	freopen("thu.inp","r",stdin);
	scanf("%s",s);
	process();
}

