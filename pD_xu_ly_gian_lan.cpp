#include <bits/stdc++.h>
using namespace std;
int n,m;
map<string,string> mp;
map<string,string> kq;
set<string> se;
void input()
{
	cin>>n;
	cin.ignore();
	while (n--)
	{
		string x,y;
		cin>>x;
		getline(cin,y);
		mp[x]=y;
		kq[x]="OK";
	}
}
void process()
{
	cin>>m;
	while (m--)
	{
		string tmp,a,b;
		cin>>tmp; cin>>tmp;
		cin>>a>>b;
		se.insert(a);
		if (b!="code.ptit.edu.vn") kq[a]="FAIL";
	}
	for (pair<string,string> k : mp)
		if (!se.count(k.first)) kq[k.first]="FAIL";
	for (pair<string,string> k : mp) 
	cout<<k.first<<""<<k.second<<" "<<kq[k.first]<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
