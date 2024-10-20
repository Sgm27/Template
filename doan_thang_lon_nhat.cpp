#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
struct record{
	ll x,y;
	ll sum()
	{
		return x+y;
	}
	ll Min()
	{
		return min(x,y);
	}
	ll Max()
	{
		return max(x,y);
	}
};
record a[105];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
}
void process()
{
	ll Min=1e9,Max=-1e9;
	for (int i=1;i<=n;i++)
	{
		Min=min(Min,a[i].Min());
		Max=max(Max,a[i].Max());	
	} 
	for (int i=1;i<=n;i++) 
		if (a[i].x==Min && a[i].y==Max) 
		{
			cout<<i;
			return;
		}
	cout<<"-1";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
