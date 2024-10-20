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
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main()
{
    // freopen("thu.inp","r",stdin);
    int n,m;
    scanf("%d %d",&n,&m);
    swap(&n,&m);
    printf("%d %d",n,m);
}


