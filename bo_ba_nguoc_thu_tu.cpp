#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn],f[maxn];

struct Fenwick{
	int t[maxn];
	void init()
	{
		memset(t,0,sizeof(t));
	}
	void update(int x,int val)
	{
		for(;x<=n;x+=x&-x) t[x]+=val;
	}
	int get(int x)
	{
		int ans=0;
		for(;x>0;x-=x&-x) ans+=t[x];
		return ans;
	}
} fw;


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
		cin>>n;	
		FOR(i,1,n) cin>>a[i];
		fw.init();
		FOD(i,n,1)
		{
			f[i]=fw.get(a[i]-1);
			fw.update(a[i],1);
		}
		int ans=0;
		fw.init();
		FOD(i,n,1)
		{
			ans+=fw.get(a[i]-1);
			fw.update(a[i],f[i]);
		}
		cout<<ans<<'\n';
	}
}
