#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dem=0,a[10000],s[10000];
ll N = 100000;
bool check[100001];
set<ll> se;
void sang() {
	s[0]=0;
	se.insert(0);
	ll N = 100000;
bool check[100001];
  for (int i = 2; i <= N; i++) {
    check[i] = true;
  }
  for (int i = 2; i <= N; i++) {
    if (check[i] == true) {
    	dem++;
    	a[dem]=i;
    	s[dem]=s[dem-1]+i;
    	se.insert(s[dem]);
      for (int j = 2 * i; j <= N; j += i) {
        check[j] = false;
      }
    }
	}
}
void process(ll n)
{
	int cnt;
	cnt=0;
	for (ll x : se)
	{
		if (x-n<0) continue;
		if (se.count(x-n)) cnt++;
	}
	cout<<cnt<<endl;
}
int main()
{
	sang();
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		ll n; cin>>n;
		process(n);
	}
}
