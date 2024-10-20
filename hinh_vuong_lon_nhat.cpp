#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int n,m,a[maxn][maxn],sum[maxn][maxn];
void calc_prefix()
{
    FOR(i,1,n)
        FOR(j,1,m)
        {
            sum[i][j]=a[i][j];
            sum[i][j]+=sum[i-1][j];
            sum[i][j]+=sum[i][j-1];
            sum[i][j]-=sum[i-1][j-1];
        }
}
pii f(int x)
{
    int sub_sum;
    pii res={0,0};
    FOR(i,1,n-x+1)
        FOR(j,1,m-x+1)
        {
            sub_sum=sum[i+x-1][j+x-1];
            sub_sum-=sum[i-1][j+x-1];
            sub_sum-=sum[i+x-1][j-1];
            sub_sum+=sum[i-1][j-1];
            if (sub_sum==x*x) res.first=x, res.second++;
        }
    return res;
}
void process()
{
    int l=0,r=min(n,m)+1;
    pii ans;
    while (r-l>1)
    {
        int m=(l+r)/2;
        pii tmp=f(m);
        if (tmp.first) l=m, ans=tmp;
        else r=m;
    }
    cout<<ans.first<<" "<<ans.second;
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n)
        FOR(j,1,m) cin>>a[i][j];
    calc_prefix();
    process();
}
