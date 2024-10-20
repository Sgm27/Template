#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
struct trie{
    int exist,count;
    int child[2];
} t[maxn];
int cnt=0,a[maxn];
void add(int a[],int n)
{
    int node=0;
    for (int i=0;i<n;i++)
    {
        int id=a[i];
        if (t[node].child[id]==0) t[node].child[id]=++cnt;
        node=t[node].child[id];
        t[node].count++;
    }
    t[node].exist++;
}
int get(int a[],int n)
{
    int node=0,ans=0;
    for (int i=0;i<n;i++)
    {
        int id=a[i];
        if (t[node].child[id]==0) return ans;
        node=t[node].child[id];
        ans+=t[node].exist;
    }
    return ans+t[node].count-t[node].exist;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>m>>n;
    while (m--)
    {
        int tmp,x; cin>>tmp;
        for (int i=0;i<tmp;i++) cin>>x, a[i]=x;
        add(a,tmp);
    }
    while (n--)
    {
        int tmp,x; cin>>tmp;
        for (int i=0;i<tmp;i++) cin>>x, a[i]=x;
        cout<<get(a,tmp)<<"\n";
    }
}

