#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
#define pii pair<int,int>
pair<int,int> a[maxn];
int n,d[maxn];
priority_queue<pii,vector<pii>,greater<pii>> Q;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        int x; cin>>x;
        Q.push({x,i});
    }
    int ans=0;
    while (!Q.empty())
    {
        pii x=Q.top(); 
        Q.pop();
        if (d[x.second]) continue;
        d[x.second-1]=1; d[x.second]=1; d[x.second+1]=1;
        ans++;
    }
    cout<<ans;
}

