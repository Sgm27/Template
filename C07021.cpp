#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct SinhVien{
	int msv;
	float mon1,mon2,mon3,tong;
	char ten[105];
};
struct SinhVien a[1005];
int op[1005],cnt=0,n=0;
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
	printf("%d\n",n);
	for (int i=1;i<=cnt;i++) printf("%d ",op[i]);
	printf("\n");
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i].tong>a[j].tong)
			{
				struct SinhVien tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
	for (int i=1;i<=n;i++) 
		printf("%d %s %.1f %.1f %.1f\n",a[i].msv,a[i].ten,a[i].mon1,a[i].mon2,a[i].mon3);
}

int main()
{
	//freopen("thu.inp","r",stdin);
	while (1)
	{
		int tmp;
		scanf("%d",&tmp);
		if (tmp==3)
		{
			process();
			return 0;
		}
		if (tmp==1)
		{
			int x;
			scanf("%d",&x);
			for (int i=1;i<=x;i++)
			{
				n++;
				a[i].msv=n;
				getchar();
				gets(a[n].ten);
				scanf("%f %f %f",&a[n].mon1,&a[i].mon2,&a[i].mon3);
				a[i].tong=a[i].mon1+a[i].mon2+a[i].mon3;
			}
		}
		if (tmp==2)
		{
			int x,pos;
			scanf("%d",&x);
			op[++cnt]=x;
			for (int i=1;i<=n;i++) 
				if (a[i].msv==x) 
				{
					pos=i;
					break;
				}
			getchar();
			gets(a[pos].ten);
			scanf("%f %f %f",&a[pos].mon1,&a[pos].mon2,&a[pos].mon3);
			a[pos].tong=a[pos].mon1+a[pos].mon2+a[pos].mon3;
		}
	}
}

