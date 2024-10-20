#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct ThiSinh{
	int ma;
	char ten[150],ns[150];
	double mon1,mon2,mon3,tong;
};
struct ThiSinh a[1005];
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
	int n;
	double Max=-1;
	scanf("%d",&n);
	getchar();
	for (int i=1;i<=n;i++)
	{
		a[i].ma=i;
		gets(a[i].ten);
		scanf("%s %lf %lf %lf",a[i].ns,&a[i].mon1,&a[i].mon2,&a[i].mon3);
		getchar();
		a[i].tong=a[i].mon1+a[i].mon2+a[i].mon3;
		if (a[i].tong>Max) Max=a[i].tong;
	}
	for (int i=1;i<=n;i++) 
		if (a[i].tong==Max)
			printf("%d %s %s %.1lf\n",a[i].ma,a[i].ten,a[i].ns,a[i].tong);
}

