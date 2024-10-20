#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
pair<ll,int> a[maxn];
int n,res[maxn];
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    ll last=1e9+7,cnt=0;
    for (int i=1;i<=n;i++) 
    {
        if (a[i].first!=last)
        {
            cnt++;
            last=a[i].first;
        }
        res[a[i].second]=cnt;
    }
    for (int i=1;i<=n;i++) cout<<res[i]<<" ";
}

