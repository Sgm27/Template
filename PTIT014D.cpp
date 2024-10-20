#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(string s)
{
	ll sum=0;
	for (int i=0;i<s.length();i++) sum+=(s[i]-'0');
	while (sum>=9)
	{
		if (sum==9) return true;
		s=to_string(sum);
		sum=0;
		for (int i=0;i<s.length();i++) sum+=(s[i]-'0');
	}
	return false;
}
int main()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		string tmp;
		cin>>tmp;
		cout<<check(tmp)<<endl;
	}
}
