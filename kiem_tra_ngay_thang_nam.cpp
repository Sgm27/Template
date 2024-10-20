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
	int ngay,thang,nam;
	scanf("%d %d %d",&ngay,&thang,&nam);
	if (ngay>=1 && ngay<=31 && thang>=1 && thang<=12 && nam>=1900)
	{
		if (thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10 || thang==12) 
			if (ngay<=31)
			{
				printf("YES");
				return 0;
			}
		if (thang==4 || thang==6 || thang==9 || thang==11) 
			if (ngay<=30)
			{
				printf("YES");
				return 0;
			}
		if (thang==2)
		{
			if (ngay<=28)
			{
				printf("YES");
				return 0;
			}
			if ((nam%400==0) || (nam%4==0 && nam%100!=0))
				if (ngay==29) 
				{
					printf("YES");
					return 0;
				}
		}
		printf("N0");
	}
	else
		printf("N0");
}

