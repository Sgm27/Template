#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 30
int n,k,x[maxn],a[maxn],ans=0,sum=0;
void Try(int i)
{
    for (int j=x[i-1]+1;j<=min(x[i-1]+2,n-(k-i+1)+1);j++)
    {
        sum+=a[j];
        x[i]=j;
        if (i==k) 
            ans=max(ans,sum);
        else Try(i+1);
        sum-=a[j];
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    if (k>n) 
    {
        cout<<0;
        return 0;
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    x[0]=0;
    Try(1);
    cout<<ans;
}

