#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll b,i,n;
ll sqr(ll x) {
    return x*x;
}
ll Pow(ll a, ll b, ll MOD) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(Pow(a, b/2,MOD)) % MOD;
        else
            return a * (sqr(Pow(a, b/2,MOD)) % MOD) % MOD;
}
void process()
{
	ll MOD=Pow(10,n+1,1);
	cout<<MOD<<endl;
	ll res=b;
	for (int j=1;j<i;j++) 
		res=(Pow(res,b,MOD));
	string s=to_string(res);
	while (s.size()<n) s="0"+s;
	cout<<s<<endl;
}
int main()
{
	freopen("thu.inp","r",stdin);
	while (cin>>b)
	{
		if (b==0) return 0;
		cin>>i>>n;
		process();
	}
}
