#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1005
int n,m;
map<string,int> mp;
string a[maxn],b[maxn];
void process()
{
    int cnt=0;
    for (int i=1;i<=n;i++) 
        if (mp[a[i]]==2) cnt++;
    if (cnt%2) cout<<"YES";
    else cout<<"NO";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    if (n>m) 
    {
        cout<<"YES";
        return 0;
    }
    if (m>n)
    {
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    for (int i=1;i<=m;i++) 
    {
        cin>>b[i];
        mp[b[i]]++;
    }
    process();
}

