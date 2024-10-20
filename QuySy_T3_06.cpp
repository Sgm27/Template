#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
long UocSo;

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
void USCLN(long a,long b)
{
    while (b)
    {
        long tmp=a;
        a=b;
        b=tmp%b;
    }
    UocSo=a;
}

int main()
{
	long a, b;
	
	scanf("%ld%ld",&a, &b);
	if(a> 0 && b>0)
	{
		USCLN(a,b);
		printf("%ld\n%lld", UocSo, (long long) a*b/UocSo);
	}
}
