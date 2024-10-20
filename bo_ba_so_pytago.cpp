#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
ll a[5005],n;
int Find(int l,int r,ll key)
{
    while (l<r)
    {
        if (a[l]+a[r]==key) return 1;
        if (a[l]+a[r]<key) l++;
        else r--;
    }
    return 0;
}
void process()
{
    sort(a+1,a+1+n);
    for (int i=n;i>=3;i--)
    {
        if (Find(1,i-1,a[i])) 
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) 
        {
            cin>>a[i];
            a[i]=a[i]*a[i];
        }
        process();
    }   
}

