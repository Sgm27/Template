#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,m,a[maxn],b[maxn],remain[maxn];
bool used[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i], remain[a[i]]++, remain[b[i]]++;
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        if (remain[a[i]]==1 && !used[a[i]]) 
        {
            remain[a[i]]--;
            ans++;
            used[a[i]]=1;
        }
        else
        if (remain[b[i]]==1 && !used[b[i]])
        {
            remain[b[i]]--;
            ans++;
            used[b[i]]=1;
        } 
        else
        if (!used[a[i]]) 
        {
            remain[a[i]]--;
            ans++;
            used[a[i]]=1;
        }
        else 
        if (!used[b[i]])
        {
            remain[b[i]]--;
            ans++;
            used[b[i]]=1;
        }
    }
    cout<<ans;
}

