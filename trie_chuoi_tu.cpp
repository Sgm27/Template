#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 250005
struct node{
    int depth,count=0,exist=0;
    int child[26];
};
int Min=25,Max=0,cnt=0,dp[maxn];
node t[maxn];
void add(string s)
{
    int x=0;
    for (char c : s)
    {
        int id=c-'a';
        Max=max(Max,id); Min=min(Min,id);
        if (t[x].child[id]==0) t[x].child[id]=++cnt;
        x=t[x].child[id];
        t[x].count++;
    }
    t[x].exist=1;
}
void process()
{
    for (int i=cnt;i>=0;i--)
    {
        for (int j=Min;j<=Max;j++)
            if (t[i].child[j]) dp[i]=max(dp[i],dp[t[i].child[j]]);
        dp[i]+=t[i].exist;
    }
    cout<<dp[0];
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    t[0].depth=0;
    int n; cin>>n;
    while (n--)
    {
        string tmp; cin>>tmp;
        add(tmp);
    }
    process();
}

