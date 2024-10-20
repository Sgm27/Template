#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxbit 19
const int MOD=1e9+7,INF=9e18;
#define maxn 300005
int n,q,a[maxn];
struct Node{
	Node *child[2];
	int count;
	Node()
	{
		memset(child,0,sizeof(child));
		count = 0;
	}
};
Node *root = new Node();
void Add(int val)
{
	Node *p = root;
	FOD(i,maxbit,0)
	{
		int id = (val >> i) & 1;
		if (p->child[id] == NULL) p->child[id] = new Node();
		p = p->child[id];
		p->count++;
	}
}
int findMEX(int val)
{
	Node *p = root;
	int ans = 0;
	FOD(i,maxbit,0)
	{
		int id = (val >> i) & 1;
		if (id == 0)
		{
			if (p->child[0] != NULL && p->child[0]->count == (1<<i))
			{
				ans += (1<<i);
				if (p->child[1] != NULL) p = p->child[1];
				else break;
			}
			else
			{
				if (p->child[0] != NULL) p = p->child[0];
				else break;
			}
		}
		else
		{
			if (p->child[1] != NULL && p->child[1]->count == (1<<i))
			{
				ans += (1<<i);
				if (p->child[0] != NULL) p = p->child[0];
				else break;
			}
			else
			{
				if (p->child[1] != NULL) p = p->child[1];
				else break;
			}
		}
	}
	return ans;
}
unordered_map<int,int> D;
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>q;
	FOR(i,1,n) 
	{
		cin>>a[i];
		if (!D[a[i]])
		{
			Add(a[i]);
			D[a[i]] = 1;
		}
	}
	int curXor = 0;
	while (q--)
	{
		int val; cin>>val;
		curXor ^= val;
		cout<<findMEX(curXor)<<"\n";
	}
}
