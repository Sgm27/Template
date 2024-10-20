#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
char tmp_ts[25];
ll res=0,left,right;
int len(ll k)
{
    int cnt=0;
    while (k)
    {
        k/=10;
        cnt++;
    }
    return cnt;
}
ll Next(ll k)
{
    ll tmp=k;
    ll a[25],nmax=0;
    while (tmp)
    {
        a[++nmax]=tmp%10;
        tmp/=10;
    }
    ll x=a[nmax]+1,check=1,nho=0;
    for (int i=1;i<nmax;i++) x*=10;
    left=x;
    if (a[1]>a[nmax]) nho=1;
    else a[1]=a[nmax];
    ll cs=2;
    while (nho)
    {
        a[cs]+=nho;
        nho=0;
        if (a[cs]>=10) 
        {
            a[cs]-=10;
            nho=1;
            cs++;
        }
    }
    if (a[nmax]!=a[1]) a[1]=a[nmax];
    ll y=0;
    for (int i=nmax;i>=1;i--)
        y=y*10+a[i];
    // printf("%lld %lld",y,left);
    if (y<10) 
    {
        left=10;
        return 9-y+1;
    }
    if (y>=left || len(y)<=2) return 0;
    tmp=0; x=0;
    for (int i=nmax-1;i>1;i--)
    {
        x=x*10+a[i];
        tmp=tmp*10+9;
    }
    return tmp-x+1;
}
ll Pre(ll k)
{
    int cs=0,a[25],nmax=0;
    ll tmp=k;
    while (tmp)
    {
        a[++nmax]=tmp%10;
        tmp/=10;
    }
    ll y=a[nmax];
    for (int i=1;i<nmax;i++) y*=10;
    right=y;
    if (a[1]<a[nmax]) cs=1;
    a[1]=a[nmax];
    tmp=0;
    for (int i=nmax-1;i>1;i--) tmp=tmp*10+a[i];
    return tmp+1-cs;
}

int main()
{
//    freopen("thu.inp","r",stdin);
    ll l,r;
    scanf("%lld %lld",&l,&r);
    res=Pre(r)+Next(l)+(right-left)/10;
    //printf("%lld %lld\n",left,right);
    printf("%lld",res);
}
