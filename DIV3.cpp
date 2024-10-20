#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
#define bit(i,n) ((n>>i)&1)
int cnt[4],a[25];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n,nmax=-1;
    int ans=0;
    cin>>n;
    while (n)
    {
        a[++nmax]=n%10;
        n/=10;
    }
    nmax++;
    for (int mask=0;mask<(1<<nmax);mask++)
    {
        int sum=0;
        for (int i=0;i<nmax;i++)
            if (bit(i,mask)) sum+=a[i];
        if (sum%3==0) ans=max(ans,(int)__builtin_popcount(mask));
    }
    cout<<nmax-ans;
}

