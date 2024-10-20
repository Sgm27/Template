#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
struct SanPham{
    int maso,gia;
    char ten[250];
};
struct SanPham a[1005];
int n=0;
void in(struct SanPham a[105],int n)
{
    for (int i=1;i<=n-1;i++)
        for (int j=i+1;j<=n;j++)
            if (a[i].maso>a[j].maso)
            {
                struct SanPham tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
    for (int i=1;i<=n;i++) printf("%d %s %d\n",a[i].maso,a[i].ten,a[i].gia);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    while (1)
    {
        int x;
        scanf("%d",&x);
        if (x==1)
        {
            int sl;
            scanf("%d",&sl);
            printf("%d\n",sl);
            while (sl--)
            {
                n++;
                scanf("%d",&a[n].maso);
                getchar();
                gets(a[n].ten);
                scanf("%d",&a[n].gia);
            }
        }
        if (x==2)
        {
            struct SanPham k;
            int ms,pos;
            scanf("%d",&ms);
            printf("%d\n",ms);
            for (int i=1;i<=n;i++) 
                if (a[i].maso==ms) 
                {
                    pos=i;
                    break;
                }
            a[pos].maso=ms;
            getchar();
            gets(a[pos].ten);
            scanf("%d",&a[pos].gia);
        }
        if (x==3)
        {
            in(a,n);
            return 0;
        }
    }
}
