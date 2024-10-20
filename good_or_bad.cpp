#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 100005
int nnode,n;
string a[maxn];
struct trie{
    int child[26],count;
    int exist;
} t[maxn*4];
void add(string s)
{
    int node=0;
    for (char c : s)
    {
        int id=c-'a';
        if (!t[node].child[id]) t[node].child[id]=++nnode;
        node=t[node].child[id];
        t[node].count++;
    }
    t[node].exist++;
}
bool check(string s)
{
    int node=0;
    bool have_pre=false;
    for (int i=0;i<s.length();i++)
    {
        int id=s[i]-'a';
        node=t[node].child[id];
        if (i!=s.length()-1 && t[node].exist) have_pre=true;
    }
    if (t[node].count>=2 || t[node].exist>=2) have_pre=true;
    return have_pre;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    bool flag=false; 
    string ans;
    FOR(i,1,n)
    {
        cin>>a[i];
        add(a[i]);
        if (check(a[i]))
        {
            flag=true;
            ans=a[i];
            break;
        }
    }
    if (flag) 
    {
        cout<<"BAD SET\n";
        cout<<ans;
    }
    else cout<<"GOOD SET";
}
