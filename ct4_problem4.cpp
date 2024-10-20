#include <bits/stdc++.h>
using namespace std;
string s,t,a[10005];
set<string> se;
void input()
{
	getline(cin,s);
	getline(cin,t);
}
void process()
{
	int dem=0;
	stringstream ss(t);
	string tmp;
	while (ss >> tmp)
	{
		string k="";
		for (int i=0;i<tmp.length();i++) k+=tolower(tmp[i]);
		se.insert(k);
	}
	stringstream px(s);
	string x;
	while (px >> x)
	{
		string kk="";
		for (int i=0;i<x.length();i++) kk+=tolower(x[i]);
		if (!se.count(kk))
		{
			dem++;
			a[dem]=kk;
			se.insert(kk);
		}
	}
	sort(a+1,a+1+dem);
	for (int i=1;i<=dem;i++) cout<<a[i]<<" ";
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
