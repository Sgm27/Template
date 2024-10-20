/*
    đề bài : đếm số lượng cách tách xâu X thành các xâu con sao cho các 
    xâu con đều thuộc tập s
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD=1337377;
#define maxn 300005
string s;
struct node
{
    int exist=0,count=0;
    int child[26];
};
node t[maxn];
int cnt=0,dp[maxn];
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
void process()
{
    int len=s.length();
    s=" "+s;
    dp[0]=1;
    for (int i=0;i<len;i++)
        if (dp[i])
        {
            int x=0;
            for (int j=i+1;j<=len;j++)  
            {
                int id=s[j]-'a';
                if (t[x].child[id]==0) break;
                x=t[x].child[id];
                if (t[x].exist!=0) dp[j]=(dp[j]+dp[i])%MOD;
            }
        }
    cout<<dp[len];
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    int n;
    cin>>n;
    while (n--)
    {
        string tmp;
        cin>>tmp;
        add(tmp);
    }
    process();
}

