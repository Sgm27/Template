#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 100005
vector<int> com;
vector<int> pos[maxn];
int n,q,a[maxn];
int get_pos(int x)
{
    int ans = lower_bound(com.begin(),com.end(),x) - com.begin();
    if (com[ans] == x) return ans;
    return -1;
}
void compress()
{
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end()) - com.begin());
    FOR(i,1,n)
    {
        int p = get_pos(a[i]);
        pos[p].push_back(i);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i], com.push_back(a[i]);
    compress();
    while (q--)
    {
        int l,r,val,fre;
        cin>>l>>r>>val>>fre;
        int v = get_pos(val);
        if (v == -1) cout<<"-1\n";
        else
        {
            int L = lower_bound(pos[v].begin(),pos[v].end(),l) - pos[v].begin();
            int R = upper_bound(pos[v].begin(),pos[v].end(),r) - pos[v].begin() - 1;
            if (R - L + 1 < fre) cout<<"-1\n";
            else cout<<pos[v][L+fre-1]<<"\n";
        }
    }
}
