#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,q;
string s[maxn];
struct Trie{
    Trie * child[26];
    set<int> count;
    set<int> exist;
    Trie() 
    {
        memset(child,0,sizeof(child));
        count.insert(n+1);
        exist.insert(n+1);
    };
};
Trie *root=new Trie();
void add(string s,int id)
{
    Trie *p=root;
    for (char c : s)
    {
        int k=c-'a';
        if (p -> child[k] == NULL) p -> child[k]=new Trie();
        p=p->child[k];
        p->count.insert(id);
    }
    p->exist.insert(id);
}
void del(string s,int id)
{
    Trie *p=root;
    for (char c : s)
    {
        int k=c-'a';
        p=p->child[k];
        p->count.erase(id);
    }
    p->exist.erase(id);
}
bool query1(int l,int r,string s)
{
    Trie *p=root;
    for (char c : s)
    {
        int k=c-'a';
        if (p->child[k] == NULL) return false;
        p=p->child[k];
        int pos=*p->exist.lower_bound(l);
        if (pos<=r) return true;
    }
    return false;
}
bool query2(int l,int r,string s)
{
    Trie *p=root;
    for (char c : s)
    {
        int k=c-'a';
        if (p->child[k] == NULL) return false;
        p=p->child[k];
    }
    int pos=*p->count.lower_bound(l);
    return pos<=r;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) 
    {
        cin>>s[i];
        add(s[i],i);
    }
    cin>>q;
    while (q--)
    {
        int type,id; cin>>type;
        string t;
        if (type==1) 
        {
            cin>>id>>t;
            del(s[id],id);
            s[id]=t;
            add(s[id],id);
        }
        else
        if (type==2) 
        {
            int l,r;
            cin>>l>>r>>t;
            if (query1(l,r,t)) cout<<"Y\n";
            else cout<<"N\n";
        }
        else
        {
            int l,r;
            cin>>l>>r>>t;
            if (query2(l,r,t)) cout<<"Y\n";
            else cout<<"N\n";
        }
    }
}
