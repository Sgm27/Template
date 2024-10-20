#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
typedef double db;
struct tamgiac{
	db a,b,c,dt;
};
struct tamgiac a[100005];
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
db dientich(db a,db b,db c)
{
	db p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%lf %lf %lf",&a[i].a,&a[i].b,&a[i].c);
		a[i].dt=dientich(a[i].a,a[i].b,a[i].c);
	}
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i].dt>a[j].dt)
			{
				struct tamgiac tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
	for (int i=1;i<=n;i++)
		printf("%.0lf %.0lf %.0lf\n",a[i].a,a[i].b,a[i].c);
}

