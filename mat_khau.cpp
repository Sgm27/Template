#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base1 = 137, base2 = 131;
#define maxn 100005
int n,p1[15],p2[15];
string s[maxn];
struct Hashing{
	vector<int> hash1,hash2;
	int SZ;
	void init(string cur)
	{
		SZ = cur.size();
		cur = " " + cur;
		hash1.resize(SZ + 1);
		hash2.resize(SZ + 1);
		FOR(i,1,SZ) 
		{
			hash1[i] = (hash1[i-1]*base1 + cur[i] - 'a' + 1) %MOD;
			hash2[i] = (hash2[i-1]*base2 + cur[i] - 'a' + 1) %MOD;
		}
	}
	int getHash1(int l,int r)
	{
		return (hash1[r] - hash1[l-1]*p1[r-l+1] + MOD*MOD) %MOD;
	}
	int getHash2(int l,int r)	
	{
		return (hash2[r] - hash2[l-1]*p2[r-l+1] + MOD*MOD) %MOD;
	}
	pii getHash(int l,int r)
	{
		pii ans;
		ans.first = getHash1(l,r);
		ans.second = getHash2(l,r);
		return ans;
	}
	pii self()
	{
		pii ans;
		ans.first = getHash1(1,SZ);
		ans.second = getHash2(1,SZ);
		return ans;
	}
};
Hashing HS[maxn];
map<pii,int> number;
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	p2[0] = p1[0] = 1;
	FOR(i,1,14) p1[i] = (p1[i-1] * base1) %MOD;
	FOR(i,1,14) p2[i] = (p2[i-1] * base2) %MOD;
	cin>>n;	
	FOR(i,1,n)
	{
		cin>>s[i];
		HS[i].init(s[i]);
		number[HS[i].self()]++;
	}
	int ans = 0;
	map<pii,int> have;
	FOR(i,1,n)
	{
		have.clear();
		FOR(j,1,HS[i].SZ) 
			FOR(k,j,HS[i].SZ)
			{
				pii curHash = HS[i].getHash(j,k);
				if (have[curHash]) continue;
				ans += number[curHash];
				have[curHash] = 1;
			}
	}
	cout<<ans - n;
}	
