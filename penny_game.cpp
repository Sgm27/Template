#include <bits/stdc++.h>
using namespace std;
void process(int tt,string s)
{
	map<string,int> mp;
	cout<<tt<<" ";
	int n=s.length();
	for (int i=0;i<=37;i++)
	{
		string tmp="";
		for (int j=i;j<=i+2;j++) tmp+=s[j];
		mp[tmp]++;
	}
	cout<<mp["TTT"]<<" "<<mp["TTH"]<<" "<<mp["THT"]<<" "<<mp["THH"]<<" "<<mp["HTT"]<<" "<<mp["HTH"]<<" "<<mp["HHT"]<<" "<<mp["HHH"]<<endl;
	cout<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		string s; cin>>s;
		process(n,s);
	}
}
