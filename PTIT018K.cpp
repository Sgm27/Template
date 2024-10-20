#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1005
int n,p,q,a[maxn],d[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>p>>q;
        if (p>q) swap(p,q);
        for (int i=1;i<=n;i++) 
        {
            cin>>a[i];  	
            d[i]=1e9;
        }
        d[0]=1e9; d[n+1]=1e9;
        d[p]=0;
        for (int i=1;i<=n;i++)
            if (a[i]==a[p] && i!=p) d[i]=1;
        for (int i=p-1;i>=1;i--)
        {
            d[i]=min({d[i],d[i+1]+1,d[i-1]+1});
            for (int j=1;j<=n;j++)
                if (j!=i && a[j]==a[i]) d[j]=min(d[j],d[i]+1);
        }
        for (int i=p+1;i<=n;i++)
        {
            d[i]=min({d[i],d[i+1]+1,d[i-1]+1});
            for (int j=1;j<=n;j++)
                if (j!=i && a[j]==a[i]) d[j]=min(d[j],d[i]+1);
        }
        // for (int i=1;i<=n;i++) cout<<d[i]<<" "; cout<<"\n";
        cout<<d[q]<<"\n";
    }
}

