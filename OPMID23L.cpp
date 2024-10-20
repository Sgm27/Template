#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int n,x[25],cnt=0,cnt5;

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
void Update()
{
    for (int i=1;i<=n;i++) printf("%d ",x[i]);
    if (x[1]==4 ) cnt5++;
    printf("\n");
}
void Try(int i)
{
    for (int j=x[i-1];j<=n;j++)
    {
        x[i]=j;
        if (i==n) 
        {
            cnt++;
            Update();
        }
        else Try(i+1);
    }
}

int main()
{
   freopen("thu.inp","r",stdin);
   freopen("thu.out","w",stdout);
    scanf("%d",&n);
    x[0]=1;
    Try(1);
    printf("%d %d %d",cnt,cnt*2-n,cnt5);
}
