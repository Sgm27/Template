#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 105
int n,c,d,a[maxn],sum[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        bool flag=false;
        cin>>n>>c>>d;
        for (int i=1;i<=n;i++) cin>>a[i];
        if (n==1) 
        {
            cout<<"YES\n";
            continue;
        }
        sort(a+1,a+1+n);
        for (int i=1;i<=n;i++)
            if ((a[i]-a[1]<=c && a[n]-a[i+1]<=d) || (a[i]-a[1]<=d && a[n]-a[i+1]<=c)) 
            {
                cout<<"YES\n";
                flag=true;
                break;
            }
        if (!flag) cout<<"NO\n";
    }
}

