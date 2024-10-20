#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main()
{
	freopen("thu.inp","r",stdin);
	freopen("thu.ans","w",stdout);
	int tc; cin>>tc;
	while (tc--)
	{
		cin>>s1>>s2;
		string tmp1="",tmp2=""; 
		for (int i=0;i<s1.length();i++)
			if (s1[i]=='6') tmp1+="5";
			else tmp1+=s1[i];
		for (int i=0;i<s2.length();i++)
			if (s2[i]=='6') tmp2+="5";
			else tmp2+=s2[i];
		cout<<stoll(tmp1)+stoll(tmp2)<<" ";
		tmp1="",tmp2=""; 
		for (int i=0;i<s1.length();i++)
			if (s1[i]=='5') tmp1+="6";
			else tmp1+=s1[i];
		for (int i=0;i<s2.length();i++)
			if (s2[i]=='5') tmp2+="6";
			else tmp2+=s2[i];
		cout<<stoll(tmp1)+stoll(tmp2);	
		cout<<"\n";
	}
}
