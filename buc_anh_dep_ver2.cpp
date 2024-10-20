#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 300009
int n,c,a[maxn],t[maxn * 4];
vector<int> fre[maxn / 3];
int Merge(int NodeL,int NodeR,int l,int r)
{
	int need = (r-l+1) >> 1;
	if (NodeL != -1)
	{
		int freL = upper_bound(fre[NodeL].begin(),fre[NodeL].end(),r) - lower_bound(fre[NodeL].begin(),fre[NodeL].end(),l);
		if (freL > need) return NodeL; 
	}
	if (NodeR != -1)
	{
		int freR = upper_bound(fre[NodeR].begin(),fre[NodeR].end(),r) - lower_bound(fre[NodeR].begin(),fre[NodeR].end(),l);
		if (freR > need) return NodeR;
	}
	return -1;
}
void build(int id,int l,int r)
{
	if (l==r) 
		return t[id] = a[l], void();
	int m = l+r >> 1;
	build(id << 1,l,m);
	build(id << 1 | 1,m+1,r);
	t[id] = Merge(t[id << 1],t[id << 1 | 1],l,r);
}
int get(int id,int l,int r,int u,int v)
{
	if (r<u || l>v) return -1;
	if (l>=u && r<=v) return t[id];
	int m = l+r >> 1;
	int L = get(id << 1,l,m,u,v);
	int R = get(id <<1 | 1,m+1,r,u,v);
	return Merge(L,R,u,v);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>c;
	FOR(i,1,n)
	{
		cin>>a[i];
		fre[a[i]].push_back(i);
	}
	build(1,1,n);
	int q; cin>>q;
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		int ans = get(1,1,n,l,r);
		if (ans == -1) cout<<"no\n";
		else cout<<"yes "<<ans<<"\n";
	}
}
