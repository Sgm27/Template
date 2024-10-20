#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int INF=9e18;
#define maxn 25
int mod,a[maxn];
struct matrix
{
    int val[maxn][maxn];
    int sz;
    matrix (int n)
    {
        sz=n;
        FOR(i,0,n)
            FOR(j,0,n) val[i][j]=0;
    }
    matrix operator * (matrix b)
    {
        matrix c(sz);
        for (int i=0;i<sz;i++)
            for (int j=0;j<sz;j++)
                for (int k=0;k<sz;k++)
                    (c.val[i][j]+=val[i][k]*b.val[k][j])%=mod;
        return c;
    }
    matrix Pow(int k)
    {
        matrix c(sz);
        for (int i=0;i<sz;i++) c.val[i][i]=1;
        for (matrix i = (*this);k;i = i*i,k/=2)
            if (k & 1) c=c*i;
        return c;
    }
};
bool nto(int k)
{
    if (k==2 || k==3) return 1;
    if (k%2==0 || k%3==0 || k<2) return 0;
    int i=5;
    while (i<=sqrt(k))
    {
        if (k%i==0 && k%(i+2)==0) return 0;
        i+=6;
    }
    return 1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k; cin>>n>>k>>mod;
        matrix ans(n);
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
            {
                if (nto(6*a[i]+a[j])) ans.val[i][j]=1;
                if (nto(6*a[j]+a[i])) ans.val[j][i]=1;
            }
        ans=ans.Pow(k-1);
        int res=0;
        for (int i=0;i<n;i++)
            (res+=ans.val[n-1][i])%=mod;
        cout<<res<<"\n";
    }
}
