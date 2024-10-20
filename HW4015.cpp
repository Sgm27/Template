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
void chuanhoa(char s[])
{
    int n=0;
    char a[150][150];
    char *token=strtok(s," ");
    while (token!=NULL)
    {
        strcpy(a[++n],token);
        token=strtok(NULL," ");
    }
    for (int i=1;i<=n;i++)
    {
        char tmp[1005];
        strcpy(tmp,a[i]);
        if (tmp[0]>='a' && tmp[0]<='z') tmp[0]-=32;
        printf("%s",tmp);
    }
    printf("\n");
}

int main()
{
//    freopen("thu.inp","r",stdin);
    int tc;
    scanf("%d",&tc);
    getchar();
    while (tc--)
    {
        char s[1005];
        gets(s);
        chuanhoa(s);
    }
}
