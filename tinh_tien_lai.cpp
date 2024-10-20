#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;

int main()
{
	freopen("thu.inp","r",stdin);
	freopen("thu.ans","w",stdout);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		ll tmp=a*b*c;
		printf("%lld",tmp/100);
		if (tmp%100==0) 
		{
			printf("\n");
			continue;
		}
		else{
			ll x=tmp%100;
			if (x<10) 
			{
				printf(".%.2lld",x);
			}
			else{
				if (x%10==0) 
					printf(".%lld",x/10);
				else printf(".%lld",x%100);
			}
		}
		printf("\n");
	}
}

