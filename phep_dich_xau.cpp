#include <bits/stdc++.h>
using namespace std;
int d[30];
string process(int k,string tmp)
{
	string res="";
	string s=".ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
	for (int i=1;i<=s.length();i++) d[s[i]]=i;
	for (int i=0;i<tmp.length();i++) res+=s[(d[tmp[i]]+k)%28];
	reverse(res.begin(),res.end());
	return res;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int n; string s;
	while (cin>>n>>s)
	{
		if (n==0) return 0;
		else cout<<process(n,s)<<endl;
	}
}
