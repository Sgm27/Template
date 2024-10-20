#include<iostream>
using namespace std;
using ll = long long;
#define maxn 200005
int prefix[maxn],suffix[maxn],n,a[maxn];
void process()
{
    int res=0;
    // build suffix & prefix
    prefix[0]=0;
    for (int i=1;i<=n;i++) prefix[i]=prefix[i-1]+a[i];
    suffix[n+1]=0;
    for (int i=n;i>=1;i--) suffix[i]=suffix[i+1]+a[i];
    int l=1,r=n;   
    while (l<r)
    {
        if (prefix[l]==suffix[r])
        {
            res=l+(n-r+1);
            l++;
            r--;
        }
        else
        if (suffix[r]<prefix[l]) r--;
        else
        if (suffix[r]>prefix[l]) l++;
    }
    cout<<res<<"\n";
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
        for(int i=1;i<=n;i++) cin>>a[i];
        process();
    }
}

