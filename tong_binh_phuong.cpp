#include <bits/stdc++.h>
using namespace std;
string n;
void input()
{
	cin>>n;
}
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
	return res;
}
string chia(string a)
{
	string res="";
	int st=0;
	for (int i=0;i<a.length();i++)
	{
		st=st*10+(a[i]-'0');
		int tmp=st/6;
		st%=6;
		res+=(char)(tmp+'0');
	}
	while (res[0]=='0') res.erase(res.begin());
	return res;
}
void process()
{
	string res="";
	res=(nhan(n,nhan(cong(n,"1"),cong(nhan(n,"2"),"1"))));
	res=chia(res);
	cout<<res;
}
int main()
{
	input();
	process();
}
