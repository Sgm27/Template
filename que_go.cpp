#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int n,a[100005];

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
int cmp(const void *a,const void *b)
{
    int *x=(int *)a;
    int *y=(int *)b;
    return *x-*y;
}
void process()
{
    char s='"';
    qsort(a+1,n,sizeof(a[1]),cmp);
    if (a[1]+a[2]<=a[n])
    {
        printf("%cCO%c",s,s);
        return;
    }
    printf("%cKHONG%c",s,s);
}

int main()
{
    // freopen("thu.inp","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    process();
}
