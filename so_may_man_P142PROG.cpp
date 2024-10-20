#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<ll> se;
int x[15];
ll res=0,nmax;
void xuly(int n)
{
    for (int i=0;i<=9;i++)
        for (int j=0;j<=9;j++)
        {
            ll tmp=0;
            for (int k=1;k<=n;k++)  
                if (x[k])
                {
                    tmp=tmp*10+i;
                }
                else 
                    tmp=tmp*10+j;
            if (tmp && tmp<=nmax && !se.count(tmp))
            {
                se.insert(tmp);
                res++;
            }
        }
}
void Try(int i,int n)
{
    for (int j=0;j<=1;j++)
    {
        x[i]=j;
        if (i==n) 
            xuly(n);
        else Try(i+1,n);
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>nmax;
    for (int i=1;i<=9;i++)
        Try(1,i);
    if (nmax==1000000000) cout<<res+1;
    else cout<<res;
}

