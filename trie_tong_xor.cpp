#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxbit 29
#define bit(i,n) (n>>i)&1
#define maxn 100005
int cnt=0,ans=-1e9;
struct trie{
    int exist=0,count=0;
    int val,child[2];
} t[maxn];
int a[maxn];
void add(int x)
{
    int node=0;
    for (int i=maxbit;i>=0;i--)
    {
        int id=bit(i,x);
        if (!t[node].child[id]) t[node].child[id]=++cnt;
        node=t[node].child[id];
    }
    t[node].val=x;
}
int get(int x)
{
    int node=0;
    for (int i=maxbit;i>=0;i--)
    {
        int id=bit(i,x);
        if (t[node].child[1-id]) node=t[node].child[1-id];
        else node=t[node].child[id];
    }
    return t[node].val^x;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        add(a[i]);
    }
    for (int i=1;i<=n;i++) ans=max(ans,get(a[i]));
    cout<<ans;
}

