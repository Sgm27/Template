#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
struct node {
    int child[26];
    int count=0,exist=0;
};
node t[maxn];
int cnt=0;
void add(string s)
{
    int x=0;
    for (char c : s)
    {
        int id=c-'a';
        if (t[x].child[id]==0) t[x].child[id]=++cnt;
        x=t[x].child[id];
        t[x].count++;
    }
    t[x].exist++;
}
int get_cnt(string s)
{
    int x=0;
    for (char c : s)
    {
        int id=c-'a';
        if (t[x].child[id]==0) return 0;
        x=t[x].child[id];
    }
    return t[x].count;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,q;
    cin>>n;
    while (n--)
    {
        string s; cin>>s;
        add(s);
    }
    cin>>q;
    while (q--)
    {
        string s; cin>>s;
        cout<<get_cnt(s)<<"\n";
    }
}

