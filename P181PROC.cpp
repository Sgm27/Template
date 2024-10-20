#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll n,k;
void input()
{
	cin>>n>>k;
}
bool nto(ll k)
{
	if (k==2 || k==3) return true;
	if (k<2 || k%2==0 || k%3==0) return false;
	ll i=5;
	while (i<=(ll)sqrt(k))
	{
		if (k%i==0 || k%(i+2)==0) return false;
		else i+=6;
	}
	return true;
}
ll find(ll k)
{
	if (nto(k)) return k;
	for (ll i=2;i<=(ll)sqrt(k);i++) 
		if (k%i==0) return i;
}
void process()
{
	if (k<find(n)) cout<<"Yes"; else cout<<"No";
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
