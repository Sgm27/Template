#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
const int block_sz=500;
#define maxn 30004
#define limit 10004
int n,a[maxn],fw[maxn/block_sz+2][maxn];
inline void update(int Block,int x,int val)
{
	for (;x<limit;x+=x&-x) fw[Block][x]+=val;
}
inline int get(int Block,int x)
{
	int ans=0;
	for (;x>0;x-=x&-x) ans+=fw[Block][x];
	return ans;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	FOR(i,1,n) 
	{
		cin>>a[i];
		update(i/block_sz,a[i],1);
	}
	int q; cin>>q;
	while (q--)
	{
		int type,u,v;
		cin>>type>>u>>v;
		if (type)
		{
			int val; cin>>val;
			int ans=0;
			int L= u/block_sz+1;
			int R= v/block_sz-1;
			FOR(i,L,R) ans += (block_sz-get(i,val));
			if (u/block_sz != v/block_sz)
			{
				for (int i=u;i<L*block_sz;i++) ans += (a[i]>val);
				for (int i=(R+1)*block_sz;i<=v;i++) ans += (a[i]>val);  
			}
			else
				for (int i=u;i<=v;i++) ans += (a[i]>val);
			cout<<ans<<"\n"; 
		}
		else
		{
			update(u/block_sz,a[u],-1);
			update(u/block_sz,v,1);
			a[u]=v;
		}
	}
}
