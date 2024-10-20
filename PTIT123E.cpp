#include <bits/stdc++.h>
using namespace std;
string cong(string a,string b)
{
	string res="";
	while (a.length()<b.length()) a="0"+a;
	while (b.length()<a.length()) b="0"+b;
	int nho=0;
	for (int i=a.length()-1;i>=0;i--)
	{
		int tmp=(a[i]-'0')+(b[i]-'0')+nho;
		if (tmp>=10) nho=1;
		else nho=0;
		tmp%=10;
		res=(char)(tmp+'0')+res;
	}
	if (nho) res="1"+res;
	return res;
}
string nhan(string a,string b)
{
	string res="0";
	int cnt=-1;
	if (a.length()<b.length()) swap(a,b);
	for (int i=b.length()-1;i>=0;i--)
	{
		cnt++;
		string st="";
		int nho=0;
		for (int j=a.length()-1;j>=0;j--)
		{
			int tmp=(b[i]-'0')*(a[j]-'0')+nho;
			if (tmp>=10) nho=tmp/10; else nho=0;
			tmp%=10;
			st=(char)(tmp+'0')+st;
		}
		if (nho) st=(char)(nho+'0')+st;
		for (int k=1;k<=cnt;k++) st+="0";
		res=cong(res,st);
	}
	while (res[0]=='0') res.erase(res.begin());
	for (int i=res.length()+1;i<=a.length();i++) res="0"+res;
	return res;
}
bool check(string s)
{
	for (int i=2;i<=s.length();i++) 
	{
		string tmp=nhan(s,to_string(i));
	//	cout<<s<<" "<<tmp<<endl;
		bool check=false;
		for (int k=0;k<tmp.length();k++)
		{
			string tmp1=tmp.substr(0,k);
			string tmp2=tmp.substr(k,tmp.length()-k);
			cout<<tmp1<<" "<<tmp2<<endl;
			if (s==tmp2+tmp1) 
			{
				check=true;
				break;
			}
		}
		if (!check) return false;
	}
	return true;
}
int main()
{
	freopen("thu.inp","r",stdin);
//	freopen("thu2.out","w",stdout);
	//int tc; cin>>tc;
	string s;
	while (cin>>s)
	{
		if (check(s)) cout<<s<<" is cyclic"<<endl;
		else cout<<s<<" is not cyclic"<<endl;
	}
}
