#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+9,INF=4e18;
#define maxn 100005
int n,a[maxn];
struct matrix
{
    int val[5][5];
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
                    (c.val[i][j]+=val[i][k]*b.val[k][j])%=MOD;
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
unordered_map<int,int> f;
int getFibo(int x)
{
	if (f[x]) return f[x];
	matrix ans(3);
	ans.val[0][0] = 1;
	ans.val[0][1] = 1;
	ans.val[1][0] = 1;
	ans.val[1][1] = 0;

	ans = ans.Pow(x);
	f[x] = ans.val[0][1];
	f[x-1] = ans.val[1][1];
	f[x+1] = ans.val[0][0];
	return f[x];
}
int calc(int F,int fi,int se)
{
	return (se * getFibo(F) + fi * getFibo(F - 1) - se) %MOD;  
}
struct Segment_Tree{
	int st[maxn*4];
	pii lz[maxn*4];
	void build(int id,int l,int r)
	{
		if (l==r) return st[id]=a[l], void();
		int m=(l+r)/2;
		build(id*2,l,m);
		build(id*2+1,m+1,r);
		st[id]=(st[id*2]+st[id*2+1]) %MOD;
	}
	void Push(int id,int l,int r)
	{
		if (!lz[id].first && !lz[id].second) return;  
		int m = r-l >> 1;
		st[id] += calc(r - l + 2,lz[id].first,lz[id].second);
		st[id] %= MOD;
		if (l < r)
		{
			lz[id * 2].first += lz[id].first;
			lz[id * 2].second += lz[id].second;
			lz[id * 2 + 1].first += calc(m+1,lz[id].first,lz[id].second);
			lz[id * 2 + 1].second += calc(m+2,lz[id].first,lz[id].second);
			lz[id * 2].first %= MOD;
			lz[id * 2].second %= MOD;
			lz[id * 2 + 1].first %= MOD;
			lz[id * 2 + 1].second %= MOD;
		}
		lz[id]={0,0};
	}
	void update(int id,int l,int r,int u,int v)
	{
		Push(id,l,r);
		if (r<u || l>v) return;
		if (l>=u && r<=v)
		{
			lz[id].first += getFibo(l-u+1);
			lz[id].second += getFibo(l-u+1);
			lz[id].first %= MOD;
			lz[id].second %= MOD;
			Push(id,l,r);
			return;
		}
		int m = l+r >> 1;
		update(id * 2,l,m,u,v);
		update(id * 2 + 1,m+1,r,u,v);
		st[id] = (st[id * 2] + st[id * 2 + 1]) %MOD;
	}
	int get(int id,int l,int r,int u,int v)
	{
		Push(id,l,r);
		if (r<u || l>v) return 0;
		if (l>=u && r<=v) return st[id];
		int m = l+r >> 1;
		return (get(id * 2,l,m,u,v) + get(id * 2 + 1,m+1,r,u,v)) %MOD;
	}
} ST;
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int q;
	cin>>n>>q;
	FOR(i,1,n) cin>>a[i];
	ST.build(1,1,n);
	while (q--)
	{
		int type,u,v;
		cin>>type>>u>>v;
		if (type == 1)
			ST.update(1,1,n,u,v);
		else
			cout<<ST.get(1,1,n,u,v)<<"\n";
	}
}
