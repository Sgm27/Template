#include <bits/stdc++.h>
using namespace std;
string s,res;
void input()
{
	cin>>s;
	res=s;
}
void process()
{
	int n=s.length()-1;
	for (int i=0;i<=n-2;i++)
		for (int j=i+1;j<=n-1;j++)
		{
			string tmp1="",tmp2="",tmp3="";
			for (int k=0;k<=i;k++) tmp1+=s[k];
			for (int k=i+1;k<=j;k++) tmp2+=s[k];
			for (int k=j+1;k<=n;k++) tmp3+=s[k];
			reverse(tmp1.begin(),tmp1.end());
			reverse(tmp2.begin(),tmp2.end());
			reverse(tmp3.begin(),tmp3.end());
			string tmp=tmp1+tmp2+tmp3;
			if (tmp<res) res=tmp;
		}
	cout<<res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
