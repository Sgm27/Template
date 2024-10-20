#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
set<string> se;
string s[1005];
void input()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) 
        {
            char x;
            cin>>x;
            s[j]+=x;
        }
    for (int i=1;i<=m;i++) reverse(s[i].begin(),s[i].end());
}
void process()
{
    for (int i=1;i<=m;i++) se.insert(s[i]);
    int cnt=0;
    while (se.size()==m)
    {
        for (int i=1;i<=m;i++) s[i].pop_back();
        cnt++;
        se.clear();
        for (int i=1;i<=m;i++) se.insert(s[i]);
    }
    cout<<cnt-1;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

