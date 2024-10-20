#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,s,t[105],res=1e9;
void input()
{
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>t[i];
} 
ll min(ll a,ll b)
{
	if (a<b) return a;
	return b;
}
void Try(int i,int cnt,ll sum)
{
	if (sum>s || cnt>res) return;
	if (i==n+1) 
	{
		if (sum==s) res=min(res,cnt);
		return;
	}
	Try(i+1,cnt,sum);
	Try(i+1,cnt+1,sum+t[i]);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	Try(1,0,0);
	cout<<res;
}
