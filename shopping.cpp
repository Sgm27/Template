#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,c;
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>a>>b>>c;
	cout<<min(2*a+2*b,min(a+b+c,min(2*a+2*c,2*b+2*c)));
}
