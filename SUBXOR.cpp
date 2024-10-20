#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define maxbit 17
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,k,a[maxn];
struct Node{
	Node *child[2];
	int count = 0, exist = 0;
	Node()
	{
		memset(child,0,sizeof(child));
		count = exist = 0;
	}
};
Node *root = new Node();
struct Trie{
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
		p->exist++;
	}
	int lessK(int val,int k)
	{
		int ans = 0;
		Node *p = root;
		FOD(i,maxbit,0)
		{
			int id = (val >> i) & 1;
			int idk = (k >> i) & 1;
			if (idk)
			{
				if (p->child[id] != NULL)
					ans += p->child[id]->count;
				if (p->child[1^id] != NULL && p->child[1^id]->count)
					p = p->child[1^id];
				else
					break;
			}
			else 
            {
                if (p->child[id] != NULL && p->child[id]->count)
                    p = p->child[id];
                else
                    break;
            }
		}
		return ans;
	}
	void clear(Node *p = root)
	{
		if (p->child[0] != NULL && p->child[0]->count)
		{
			p->child[0]->count = 0;
			clear(p->child[0]);
		}
		if (p->child[1] != NULL && p->child[1]->count)
		{
			p->child[1]->count = 0;
			clear(p->child[1]);
		}
	}
} tree;
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
		int prefixXor = 0, answer = 0;	
		cin>>n>>k;
		tree.Add(0);
		FOR(i,1,n)
		{
			cin>>a[i];
			prefixXor ^= a[i];
			answer += tree.lessK(prefixXor,k);
			tree.Add(prefixXor);
		}
		cout<<answer<<"\n";
		tree.clear();
	}
}
