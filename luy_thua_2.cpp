// có trường hợp n m k bang 0
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define ll long long
#define pii pair<int,int>
const int INF=9e18;
#define maxn 
int n,m,k;
ll mul_mod(ll a,ll b,ll MOD)
{
	ll res=0;
	a%=MOD;
	while (b)
	{
		if (b%2) res=(res+a)%MOD;
		a=(a*2)%MOD;
		b/=2;
	}
	return res;
}
ll Pow(ll a, ll n,ll MOD)
{
	if (!n) return 1;
	if (n==1) return a;
	ll tmp=Pow(a,n/2,MOD);
	tmp=mul_mod(tmp,tmp,MOD);
	if (n%2) tmp=mul_mod(tmp,a,MOD);
	return tmp;
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
		cin>>n>>m>>k;
		if (k==1) cout<<"0\n";
		else cout<<Pow(n,m,k)<<"\n";
	}
}
