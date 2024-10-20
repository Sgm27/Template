#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s[105];
int d[105],dd[256];
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
	for (int i=1;i<=105;i++) d[i]=1;
	int res=0,n=51;
	for (int i=0;i<=n;i++)
		if (d[i])
		{
			d[i]=0;
			int r=i+1;
			while (s[r]!=s[i] && r<=n) r++;
			d[r]=0;
			int cnt=0;
			for (int k=1;k<=256;k++) dd[k]=0;
			for (int j=i+1;j<=r-1;j++) dd[(int)(s[j])]++;
			for (int j=i+1;j<=r-1;j++) 
				if (dd[(int)(s[j])]==1) cnt++;
			res+=cnt;
		}
	printf("%d",res/2);
}

int main()
{
//	freopen("thu.inp","r",stdin);
	scanf("%s",s);
	process();
}

