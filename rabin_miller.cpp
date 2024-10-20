#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int INF=9e18;
#define maxn 

int mul_mod(int a,int b,int MOD)
{
    int res=0;
    a%=MOD;
    while (b)
    {
        if (b%2) res=(res+a)%MOD;
        a=(a*2)%MOD;
        b/=2;
    }
    return res;
}
int Pow(int a, int n,int MOD)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2,MOD);
    tmp=mul_mod(tmp,tmp,MOD);
    if (n%2) tmp=mul_mod(tmp,a,MOD);
    return tmp;
}
bool check(int d,int n)
{
    int a=rand()%(n-3)+2;
    int x=Pow(a,d,n);
    if (x==1 || x==n-1) return 1;
    while (d!=n-1)
    {
        x=mul_mod(x,x,n);
        d*=2;
        if (x==n-1) return 1;
    }
    return 0;
}
bool Miller(int n)
{
    if (n==2 || n==3) return true;
    if (n%2==0 || n%3==0) return false;
    if (n<5) return false;
    int d=n-1;
    while (d%2==0) d/=2;
    FOR(i,1,5)
        if (!check(d,n)) return 0;
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
        int n; cin>>n;
        if (Miller(n)) cout<<"YES\n"; else cout<<"NO\n";
    }
}
