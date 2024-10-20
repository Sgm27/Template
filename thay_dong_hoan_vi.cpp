#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
multiset<int> candidates;
int n,q,a[maxn],b[maxn],pos[maxn],cnt[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i], pos[a[i]] = i, candidates.insert(0);
    FOR(i,1,n) 
    {
        cin>>b[i];
        int dis;
        if (i >= pos[b[i]]) dis = i - pos[b[i]];
        else dis = i + n - pos[b[i]];
        candidates.erase(candidates.find(cnt[dis]));
        cnt[dis]++;
        candidates.insert(cnt[dis]);
    }
    while (q--)
    {
        int p1,p2; cin>>p1>>p2; 
        int dis1;
        if (p1 >= pos[b[p1]]) dis1 = p1 - pos[b[p1]];
        else dis1 = p1 + n - pos[b[p1]];
        candidates.erase(candidates.find(cnt[dis1]));
        cnt[dis1]--;
        candidates.insert(cnt[dis1]);

        if (p2 >= pos[b[p1]]) dis1 = p2 - pos[b[p1]];
        else dis1 = p2 + n - pos[b[p1]];
        candidates.erase(candidates.find(cnt[dis1]));
        cnt[dis1]++;
        candidates.insert(cnt[dis1]);

        if (p2 >= pos[b[p2]]) dis1 = p2 - pos[b[p2]];
        else dis1 = p2 + n - pos[b[p2]];
        candidates.erase(candidates.find(cnt[dis1]));
        cnt[dis1]--;
        candidates.insert(cnt[dis1]);

        if (p1 >= pos[b[p2]]) dis1 = p1 - pos[b[p2]];
        else dis1 = p1 + n - pos[b[p2]];
        candidates.erase(candidates.find(cnt[dis1]));
        cnt[dis1]++;
        candidates.insert(cnt[dis1]);

        swap(b[p1],b[p2]);
        cout<<*candidates.rbegin()<<"\n";
    }
}
