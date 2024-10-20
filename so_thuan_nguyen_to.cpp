#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string d[5],s;
ll n=0;
vector<ll> v;
bool nto(ll k)
{
	if (k==2 || k==3) return true;
	if (k<2 || k%2==0 || k%3==0) return false;
	ll i=5;
	while (i<=(ll)(sqrt(k)))
	{
		if (k%i==0 || k%(i+2)==0) return false;
		else i+=6;
	}
	return true;
}
bool check(string s)
{
	if (!nto(stoll(s))) return false;
	ll tmp=0;
	for (int i=0;i<s.length();i++) tmp+=(s[i]-'0');
	if (!nto(tmp)) return false;
	return true; 
}
void init()
{
	d[1]="2"; d[2]="3"; d[3]="5"; d[4]="7";
}
void thu(int i)
{
	for (int j=1;j<=4;j++)
	{
		s+=d[j];
		if (s.length()<=n)
		{
			if (check(s)) 
			{
				cout<<s<<endl;
				v.push_back(stoll(s));
			}
		}
		else thu(i+1);
		s.pop_back();
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	init();
//	while (n<=8) 
	{
	//	n++; s="";
	n=8;
		thu(1);
	}
	cout<<v.size();
	ll tc; cin>>tc;
	while (tc--)
	{
		ll x; cin>>x;
		if (binary_search(v.begin(),v.end(),x)) cout<<"YES\n"; else cout<<"NO\n";
	}
}
