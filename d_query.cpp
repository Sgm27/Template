#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 2000005
int n,q,t[maxn],last_pos[maxn],ans[maxn];
int a[maxn];
struct query{
    int l,r,id;
} Q[maxn];
bool cmp(query a,query b)
{
    return a.r<b.r;
}
void Update(int x,int val)
{
    while (x<=n)
    {
        t[x]+=val;
        x+=x&(-x);
    }
}
int Get(int x)
{
    int ans=0;
    while (x>0)
    {
        ans+=t[x];
        x-=x&(-x);
    }
    return ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    cin>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,q) cin>>Q[i].l>>Q[i].r, Q[i].id=i;
    sort(Q+1,Q+1+q,cmp);
    int idx=1;
    FOR(i,1,n)
    {
        Update(i,1);
        if (last_pos[a[i]]) Update(last_pos[a[i]],-1);
        last_pos[a[i]]=i;
        while (i==Q[idx].r) ans[Q[idx].id]=Get(Q[idx].r)-Get(Q[idx].l-1), idx++;
    }
    FOR(i,1,q) cout<<ans[i]<<"\n";
}
