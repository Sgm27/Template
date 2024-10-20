#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[1000005];
set<ll> se;
vector<ll> res;
map<ll,ll> mp;
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		se.insert(a[i]);		
	}
}
void process()
{
	for (ll x : se) res.push_back(x);
	for (int i=res.size()-1;i>=1;i--) mp[res[i]]=res[i-1];
	mp[res[0]]=INT_MIN;
	for (int i=1;i<=n;i++) 
		if (mp[a[i]]==INT_MIN) cout<<"# "; else cout<<mp[a[i]]<<" ";
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
