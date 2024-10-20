#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1000006
int n;
pii a[maxn]; 
struct Fenwick{
	vector<int> t;
	int n;
	Fenwick(int sz)
	{
		n=sz;
		t.assign(n+1,0);
	}
	void update(int x,int val)
	{
		for (;x<=n;x+=x&-x) t[x]=max(t[x],val);
	}
	int get(int x)
	{
		int ans=0;
		for (;x>0;x-=x&-x) ans=max(ans,t[x]);
		return ans;
	}
};
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
		int answer=0;
		vector<int> com;
		cin>>n;
		Fenwick fw(n);
		FOR(i,1,n) cin>>a[i].first;
		FOR(i,1,n) cin>>a[i].second, com.push_back(a[i].second);
		sort(com.begin(),com.end());
		sort(a+1,a+1+n);
		com.resize(unique(com.begin(),com.end())-com.begin());
		FOR(i,1,n)
		{
			int PosX=lower_bound(com.begin(),com.end(),a[i].second)-com.begin()+1;
			int tmp=fw.get(PosX)+1;
			answer=max(answer,tmp);
			fw.update(PosX,tmp);
		}
		cout<<answer<<"\n";
	}
}
