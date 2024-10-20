#include <bits/stdc++.h>
using namespace std;
int n;
string st[5005],res[1005];
map<string,int> mp;
void input()
{
	cin>>n;
	cin.ignore();
	for (int i=1;i<=n;i++)
	{
		getline(cin,st[i]);
	}
}
bool check(string s)
{
	if (s[0]>='0' && s[0]<='9') return false;
	return true;
}
void process(string s)
{
	int dem=0;
	stringstream ss(s);
	string tmp,ngay;
	while (ss >> tmp)
	{
		dem++;
		if (check(tmp)) 
		{
			string k="";
			for (int i=0;i<tmp.length();i++) k+=tolower(tmp[i]);
			res[dem]=k;
		}
		else ngay=tmp;
	}
	string kq=res[dem-1];
	for (int i=1;i<=dem-2;i++) 
	{
		string x=res[i];
		kq+=x[0];
	}
	mp[kq]++;
	if (mp[kq]==1) cout<<kq<<"@xyz.edu.vn"<<endl; else cout<<kq<<mp[kq]<<"@xyz.edu.vn"<<endl;
	if (ngay[0]=='0') ngay.erase(ngay.begin());
	for (int i=0;i<ngay.length();i++)
	{
		if (ngay[i]=='/' && ngay[i+1]=='0') 
		{
			ngay.erase(ngay.begin()+i+1);
			continue;
		} 
		else 
		if (ngay[i]=='/') continue;
		cout<<ngay[i];
	}
	cout<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	for (int i=1;i<=n;i++)
	{
		process(st[i]);
	}
}

