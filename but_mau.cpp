#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a,b,c,d;
set<ll> se;
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>a>>b>>c>>d;
	se.insert(a); se.insert(b); se.insert(c); se.insert(d);
	cout<<4-se.size();
}

