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
    getchar();
    while (tc--)
    {
        int cnt=0;  
        char s[10005]="";
        gets(s);
        char *token=strtok(s," ");
        while (token!=NULL)
        {
            cnt++;
            token=strtok(NULL," ");
        }
        printf("%d\n",cnt);
    }
}
