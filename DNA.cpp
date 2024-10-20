#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
	if (a.length()!=b.length()) return a.length()>b.length();
	else return a<b;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc,n;
	cin>>tc;
	while (tc--)
	{
		cin>>n;
		map<string,pair<int,int>> mp;
		for (int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for (int j=0;j<=57;j++)
				for (int k=j+2;k<=59;k++)
				{
					string tmp=s.substr(j,k-j+1);
					if (!mp.count(tmp)) 
					{
						pair<string,pair<int,int>> x;
						x.first=tmp;
						x.second.first++;
						x.second.second=i;
						mp.insert(x);
					}
					else 
					if (mp[tmp].second!=i) 
					{
						mp[tmp].first++;
						mp[tmp].second=i;
					}
				}
		}
		bool check=false;
		vector<string> v;
		for (pair<string,pair<int,int>> k : mp)
			if (k.second.first==n) 
			{
				check=true;
				v.push_back(k.first);
			}
		if (!check) cout<<"no significant commonalities\n";
		else
		{
			sort(v.begin(),v.end(),cmp);
			cout<<v[0]<<endl;
		}
	}
}
