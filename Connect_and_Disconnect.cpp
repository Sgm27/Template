#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 300005
int n,k,par[maxn],sz[maxn],cnt_connect,u[maxn*2],v[maxn*2],o[maxn*2];
stack<int> st;
char op[maxn*2];
map<pii,int> mp;

int find_set(int u)
{
    if (u==par[u]) return u;
    return find_set(par[u]);
}

void Union(int u,int v)
{
    u=find_set(u), v=find_set(v);
    if (u==v) return;
    if (sz[u]>sz[v]) swap(u,v);
    par[u]=v;
    sz[v]+=sz[u];
    cnt_connect--;
    st.push(u);
}

void roll_back(int time)
{
    while (st.size()>time)
    {
        int u=st.top();
        st.pop();
        sz[par[u]]-=sz[u];
        par[u]=u;
        cnt_connect++;
    }
}

void solve(int l,int r)
{
    if (l==r)
    {
        if (op[l]=='?') cout<<cnt_connect<<"\n";
        return;
    }
    int m=(l+r)/2, now=st.size();

    FOR(i,m+1,r)
        if (o[i]<l) Union(u[i],v[i]);
    solve(l,m);
    roll_back(now);

    FOR(i,l,m)
        if (o[i]>r) Union(u[i],v[i]);
    solve(m+1,r);
    roll_back(now);
}

int main()
{
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    FOR(i,1,n) par[i]=i, sz[i]=1;
    FOR(i,1,k)
    {
        cin>>op[i];
        if (op[i]=='?') continue;

        cin>>u[i]>>v[i];
        if (u[i]>v[i]) swap(u[i],v[i]);
        pii x={u[i],v[i]};
        if (mp.count(x))
        {
            o[i]=mp[x];
            o[o[i]]=i;
            mp.erase(x);
        }
        else 
            mp[x]=i;
    }
    int idx=k;
    for (pair<pii,int> it : mp)
    {
        o[it.second]=++idx;
        o[idx]=it.second;
        op[idx]='-';
        u[idx]=it.first.first, v[idx]=it.first.second;
    }
    cnt_connect=n;
    solve(1,idx);
}
