#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,b;
map<ll,int> mp;
void input()
{
    cin>>n>>b;
    for (int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        mp[x]++;
    }
}
void process()
{
    ll res=0;
    for (pair<ll,int> k : mp)
    {
        if (k.first*2!=b) res+=k.second*mp[b-k.first];
    }
    res/=2;
    if (b%2)
    {
    	cout<<res;
    	return;
	} else
	{
		ll tmp=mp[b/2]-1;
		res+=(tmp+1)*tmp/2;
		cout<<res;
	}
}
int main()
{
    freopen("thu.inp","r",stdin);
    input();
    process();
}
