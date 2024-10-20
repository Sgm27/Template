#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int a[505][505],b[505][505],n,m;
char s[105];
void input()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&b[i][j]);
    scanf("%s",s);
}
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
    int check=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]!=b[i][j]) 
            {
                check=0;
                break;
            }
    if ((!check && strcmp(s,"No")==0) || (check && strcmp(s,"Yes")==0)) 
    {
        printf("Correct!");
        return;
    }
    printf("Incorrect!");
}

int main()
{
    // freopen("thu.inp","r",stdin);
    input();
    process();
}
