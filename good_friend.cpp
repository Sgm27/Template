#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,k,sum[300005][21],min_len=21,max_len=0;
string s[300005];
void input()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) 
    {
        cin>>s[i];
        int x=s[i].length();
        min_len=min(min_len,x);
        max_len=max(max_len,x);
    }
}
void process()
{
    if (n==1)
    {
        cout<<"0";
        return;
    }
    for (int j=min_len;j<=max_len;j++) sum[0][j]=0;
    for (int i=1;i<=n;i++)
    {
        int x=s[i].length();
        for (int j=min_len;j<=max_len;j++)
        {
            sum[i][j]=sum[i-1][j];
            if (j==x) sum[i][j]++;
        }
    }
    ll res=0;
    for (int i=2;i<=n;i++)
    {
        int x=s[i].length();
        if (sum[i][x]>1)
        {
            res+=sum[i][x]-sum[max(0,i-k-1)][x]-1;
        }
    }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

