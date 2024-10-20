#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int scs(ll k)
{
    ll cnt=0;
    while (k)
    {
        cnt++;
        k/=10;
    }
    return cnt;
}
void process(ll n)
{
    ll a[15],b[15],nmax=0,m=n,res=-1;
    ll x=scs(n);   
    memset(a,0,sizeof(a));
    while (n)
    {
        a[++nmax]=n%10;
        n/=10;
    }
    reverse(a+1,a+1+nmax);
    for (int i=1;i<nmax;i++)
        for (int j=i+1;j<=nmax;j++)
        {
            for (int k=1;k<=nmax;k++) b[k]=a[k];
            ll tmp=b[i];
            b[i]=b[j];
            b[j]=tmp;
            tmp=0;
            for (int k=1;k<=nmax;k++) tmp=tmp*10+b[k];
            if (tmp<m) res=max(res,tmp);
        }
    if (res!=-1) 
    {
        for (int i=scs(res);i<x;i++) cout<<"0";
        cout<<res<<endl;
    }
    else cout<<"-1\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        process(n);
    }
}

