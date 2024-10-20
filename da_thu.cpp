#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int n,a[100005],b[100005];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        ll res=0;
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int j=1;j<=n;j++) cin>>b[j];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n,greater<int>());
        for (int i=1;i<=n;i++) res+=max(a[i],b[i]);
        cout<<res<<"\n";
    }
}

