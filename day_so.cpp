#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,hai[105],nmax=0,a[100005],d[1005];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
}
int source(ll k)
{
	if (k==1) return 1;
	if (k%2) return source(k/2)+1;
	else return source(k/2);
}
void process()
{
	ll res=0;
	for (int i=1;i<=n;i++)
	{
		d[source(a[i])]++;
		res+=d[source(a[i])]-1;
	}
	cout<<res;
}
int main()
{
	memset(d,0,sizeof(d));
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
