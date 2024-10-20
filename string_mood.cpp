#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 10
#define N 2
struct matrix
{
    int val[N][N];
    matrix ()
    {
        memset(val,0,sizeof(val));
    }
    matrix operator * (matrix b)
    {
        matrix c;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                for (int k=0;k<N;k++)
                    (c.val[i][j]+=val[i][k]*b.val[k][j])%=MOD;
        return c;
    }
    matrix Pow(int k)
    {
        if (k==1) return *this;
        matrix tmp=Pow(k/2);
        tmp = tmp*tmp;
        if (k & 1) tmp=tmp * (*this);
        return tmp;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    matrix ans;
    ans.val[0][0]=20, ans.val[0][1]=7;
    ans.val[1][0]=6, ans.val[1][1]=19;
    int n; cin>>n;
    ans=ans.Pow(n);
    cout<<ans.val[1][1];
}
