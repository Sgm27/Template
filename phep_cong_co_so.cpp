#include <bits/stdc++.h>
using namespace std;
string a[1000];
map<string,int> mp;
void init()
{
	a[0]="{}";
	mp["{}"]=0;
	a[1]="{{}}";
	mp["{{}}"]=1;
	int dem=1;
	while (1)
	{
		dem++;
		string tmp="{";
		for (int i=0;i<=dem-1;i++) 
		{
			tmp+=a[i];
			if (i!=dem-1) tmp+=",";
			if (dem>20) return;
		}
		tmp+="}";
		a[dem]=tmp;
		mp[tmp]=dem;
	}
}
void process(string n,string m)
{
	cout<<a[mp[n]+mp[m]]<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	init();
	int tc;
	cin>>tc;
	while (tc--)
	{
		string n,m;
		cin>>n>>m;
		process(n,m);
	}
}
