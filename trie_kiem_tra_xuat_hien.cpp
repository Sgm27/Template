#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
struct node {
    int exist=0;
    int child[26];
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
    }
    t[x].exist++;
}
bool found(string s)
{
    int x=0;
    for (char c : s)
    {   
        int id=c-'a';
        if (t[x].child[id]==0) return false;
        x=t[x].child[id];
    }
    return t[x].exist!=0;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,q;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string tmp; cin>>tmp;
        add(tmp);
    }
    cin>>q;
    while (q--)
    {
        string tmp; cin>>tmp;
        cout<<found(tmp)<<"\n";
    }
}

