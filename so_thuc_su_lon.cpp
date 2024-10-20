#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll res,n,s;
void nhap()
{
	cin>>n>>s;
}
int tt(ll t)
{
	int kq=0;
	while (t!=0)
	{
		kq+=t%10;
		t/=10;
	}
	return kq;
}
void xl()
{
	ll k=1;
	while (k-tt(k)<s) k++;
	res=n-k+1;
	if (res<=0) cout<<0;
	else cout<<res; 
}
int main()
{
	//freopen("thu.inp","r",stdin);
	nhap();
	xl();	
}
