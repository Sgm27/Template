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


int main()
{
	//freopen("thu.inp","r",stdin);
	int tc,n;
	scanf("%d",&tc);
	for (int stt=1;stt<=tc;stt++)
	{
		printf("Test %d: ",stt);
		scanf("%d",&n);
		int i=2;
		while (n!=1)
		{
			int cnt=0;
			while (n%i==0) 
			{
				cnt++;
				n/=i;
			}
			if (cnt!=0) printf("%d(%d) ",i,cnt);
			i++;
		}
		printf("\n");
	}
}

