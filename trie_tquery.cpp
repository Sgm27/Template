#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxbit 30
#define maxn 200005
int q,nnode;
unordered_map<int,int> D;
struct trie{
    int child[2],count,exist,sum;
    int val;
}   t[4*maxn];
void add(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        if (!t[node].child[id]) t[node].child[id]=++nnode;
        node=t[node].child[id];
        t[node].count++;
        t[node].sum+=k;
    }
    t[node].exist++;
    t[node].val=k;
}
void remove(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        int tnode=t[node].child[id];
        t[tnode].count--;
        if (!t[tnode].count) 
        {
            t[node].child[id]=0;
            return;
        }
        node=tnode;
        t[node].sum-=k;
    }
    t[node].exist--;
    if (!t[node].exist) t[node].val=0;
}
int sum(int k)
{
    if (k<=0) return 0;
    int node=0,ans=0,left;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        left=t[node].child[0];
        if (id) ans+=t[left].sum;
        if (t[node].child[id]) node=t[node].child[id];
        else break;
    }
    return ans+t[node].exist*t[node].val;
}
int find(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        int left=t[node].child[0];
        if (left && t[left].count>=k) node=left;
        else
        {
            node=t[node].child[1];
            if (left) k-=t[left].count;
        }
    }
    return t[node].val;
}
int max_xor(int k)
{
    int node=0;
    FOD(i,maxbit,0)
    {
        int id=(k>>i)&1;
        if (t[node].child[1^id]) node=t[node].child[1^id];
        else node=t[node].child[id];
    }
    return t[node].val^k;
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>q;
    while (q--)
    {
        int type; cin>>type;
        if (type==1) 
        {
            int k; cin>>k;
            D[k]++;
            add(k);
        }
        else
        if (type==2)
        {
            int k; cin>>k;
            if (D[k])
            {
                remove(k);
                D[k]--;
            }
        }
        else
        if (type==3)
        {
            int l,r; cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<"\n";
        }
        else
        if (type==4)
        {
            int k; cin>>k;
            cout<<find(k)<<"\n";
        }
        else
        {
            int k; cin>>k;
            cout<<max_xor(k)<<"\n";
        }
    }
}
