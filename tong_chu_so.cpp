#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
void input()
{
	cin>>s;
}
void process()
{
	ll n=0,cnt=1;
	if (s.length()==1) {
		cout<<0;
		return;
	}
	for (int i=0;i<s.length();i++) n+=(s[i]-'0');
	while (n>9)
	{
		cnt++;
		ll res=0;
		string tmp=to_string(n);
		for (int i=0;i<tmp.length();i++) res+=(tmp[i]-'0');
		n=res;
	}
	cout<<cnt;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
