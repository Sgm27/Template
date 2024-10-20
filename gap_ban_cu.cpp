#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll l1,r1,l2,r2,k;
void input()
{
	cin>>l1>>r1>>l2>>r2>>k;
}
void process()
{
	ll res=min(r1,r2)-max(l1,l2)+1;
	if (min(r1,r2)>=k && max(l1,l2)<=k) res--;
	if (res>0) cout<<res;
	else cout<<0;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
