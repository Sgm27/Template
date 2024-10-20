#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct MatHang{
	int ma;
	char ten[150],nhom[150];
	double gianhap,giaban,loinhuan;
};
struct MatHang a[10005];
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
	//freopen("thu.inp","r",stdin);
	int n;
	scanf("%d",&n);
	getchar();
	for (int i=1;i<=n;i++)
	{
		a[i].ma=i;
		gets(a[i].ten);
		gets(a[i].nhom);
		scanf("%lf %lf",&a[i].gianhap,&a[i].giaban);
		getchar();
		a[i].loinhuan=a[i].giaban-a[i].gianhap;
	}
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i].loinhuan<a[j].loinhuan)
			{
				struct MatHang tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
	for (int i=1;i<=n;i++)
		printf("%d %s %s %.2lf\n",a[i].ma,a[i].ten,a[i].nhom,a[i].loinhuan);
}

