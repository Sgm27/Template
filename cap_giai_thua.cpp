#include <bits/stdc++.h>
using namespace std;
string giaithua(char x)
{
	if (x=='0' || x=='1') return "1";
	if (x=='2') return "2";
	if (x=='3') return "3";
	if (x=='4') return "322";
	if (x=='5') return "5";
	if (x=='6') return "53";
	if (x=='7') return "7";
	if (x=='8') return "7222";
	if (x=='9') return "7332";
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;  cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		string s,tmp="";
		cin>>s;
		for (int i=0;i<s.length();i++) tmp+=giaithua(s[i]);
		sort(tmp.begin(),tmp.end()+1,greater<char>());
		for (char x : tmp) 
			if (x!='1') cout<<x;
			else break;
		cout<<endl; 
	}
}
