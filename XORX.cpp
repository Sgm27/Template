#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxbit 30
#define maxn 200005
int n,k,a[maxn];
struct Node{
	Node *child[2];
	int val, count;
	Node()
	{
		memset(child,0,sizeof(child));
		count = val = 0;
	}
};
Node *root = new Node();
pii answer;
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
		p->val = val;
	}
	pii getMaxXor(int val)
	{
		Node *p = root;
		FOD(i,maxbit,0)
		{
			int id = (val >> i) & 1;
			if (p->child[id^1] != NULL && p->child[id^1]->count) p = p->child[id^1];
			else
			{
				if (p->child[id] != NULL && p->child[id]->count) p = p->child[id];
				else break;
			}
		}
		pii ans;
		ans.first = p->val ^ val;
		ans.second = p->val;
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
		answer = {-1,-1};
		cin>>n>>k;
		int curXor = 0;
		FOR(i,1,n)
		{
			int x; cin>>x;
			curXor ^= x;
			tree.Add(curXor);
			pii curMax = tree.getMaxXor(k ^ curXor);
			if (curMax.first > answer.first) 
			{
				answer.first = curMax.first;
				answer.second = curXor ^ curMax.second;
			}
		}
		cout<<answer.second<<"\n";
		tree.clear();
	}
}
