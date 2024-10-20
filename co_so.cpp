#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
map<string,int> mp;
void input()
{
	cin>>s;
}
void init()
{
	mp["000"]=0;
	mp["001"]=1;
	mp["010"]=2;
	mp["011"]=3;
	mp["100"]=4;
	mp["101"]=5;
	mp["110"]=6;
	mp["111"]=7;
}
void process()
{
	while (s.size()%3!=0) s="0"+s;
	int cs=0,n=s.size();
	while (cs<=n-1)
	{
		string tmp="";
		for (int i=cs;i<=cs+2;i++) tmp+=s[i];
		cs+=3;
		cout<<mp[tmp];
	}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	init();
	process();
}
