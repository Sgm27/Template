#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 5000005
int cnt;
struct trie{
    int count=0,count_fre=0,exist=0;
    int child[26];
    string val;
} t[maxn];
void add(string s)
{
    int node=0;
    for (char c : s)
    {
        int id=c-'a';
        if (!t[node].child[id]) t[node].child[id]=++cnt;
        node=t[node].child[id];
        t[node].count++;
    }
    t[node].exist++;
    t[node].count_fre++;
    t[node].val=s;
}
void Try(int node,int &ans_node)
{
    if (t[node].exist && t[node].count_fre>t[ans_node].count_fre) ans_node=node;
    else
    if (t[node].exist && t[node].count_fre==t[ans_node].count_fre && t[ans_node].val>t[node].val) 
        ans_node=node;
    for (int i=0;i<=25;i++)
        if (t[node].child[i]) Try(t[node].child[i],ans_node);
}
pair<string,int> get(string s)
{
    int node=0;
    for (char c : s)
    {
        int id=c-'a';
        if (!t[node].child[id]) return {"",-1};
        node=t[node].child[id];
    }
    int ans_node;
    Try(node,ans_node);
    return {t[ans_node].val,t[ans_node].count_fre};
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,q;
    cin>>n;
    while (n--)
    {
        string tmp;  cin>>tmp;
        add(tmp);
    }
    cin>>q;
    while (q--)
    {
        string tmp; cin>>tmp;
        pair<string,int> ans=get(tmp);
        if (ans.second==-1) cout<<"-1\n";
        else
            cout<<ans.first<<" "<<ans.second<<"\n";
    }
}

