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
    // freopen("thu.inp","r",stdin);
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        int x,y,sum;
        scanf("%d %d",&x,&y);
        int *ct1=&x;
        int *ct2=&y;
        sum=*ct1+*ct2;
        printf("%d\n",sum);
    } 
}
