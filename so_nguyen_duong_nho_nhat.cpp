#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,k,cnt1=0,a[200005];
void process()
{
    a[n+1]=INT_MAX;
    sort(a+1,a+2+n);
    if (k==0)
    {
        if (!cnt1) cout<<"1";
        else cout<<"-1";
        return;
    }
    if (a[k]!=a[k+1]) 
    {
        cout<<a[k];
        return;
    }
    cout<<"-1";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if (a[i]==1) cnt1=1;
    }
    process();
}

