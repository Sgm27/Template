#include<bits/stdc++.h>
#ifdef DS
	#include "debug.h"
#else 
	#define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
struct Node{
	int val;
	Node *left, *right;
	Node(int _val)
	{
		this -> val = _val;
		left = right = NULL;
	}
};
Node *build(int in[], int mark[], int l, int r)
{
	if (l > r) return NULL;
	int pos = l;
	FOR(i, l+1, r)
		if (mark[in[i]] < mark[in[pos]]) pos = i;
	Node *root = new Node(in[pos]);
	if (l == r) return root;
	root -> left = build(in, mark, l, pos - 1);
	root -> right = build(in, mark, pos + 1, r);
	return root;
}
vi ans;
void postOrder(Node *root)
{
	if (root == NULL) return;
	else
	{
		postOrder(root->left);
		postOrder(root->right);
		ans.push_back(root -> val);
	}
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
		int n; cin>>n;
		int in[n+1], level[n+1], mark[n+1];
		FOR(i,1,n) cin>>in[i];
		FOR(i,1,n) cin>>level[i], mark[level[i]] = i;
		Node *root = build(in, mark, 1, n);
		postOrder(root);
		for (int x : ans) cout<<x<<" ";
		ans.clear();
		cout<<"\n";
	}
}
