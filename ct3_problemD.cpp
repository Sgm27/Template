#include <bits/stdc++.h>
using namespace std;
struct mang{
	int diem,hieuso;
};
map<string,mang> mp;
vector<pair<string,mang>> v;
bool cmp(pair<string,mang> a,pair<string,mang> b)
{
	if (a.second.diem!=b.second.diem) return a.second.diem>b.second.diem;
	else if (a.second.hieuso!=b.second.hieuso) return a.second.hieuso>b.second.hieuso;
	return a.first<b.first;
}
int main()
{
	freopen("thu.inp","r",stdin);
	string X,Y,tmp;
	int x,y;
	while (cin>>X)
	{
		cin>>x>>tmp>>y>>Y;
		X.pop_back();
		Y.pop_back();
		X.erase(X.begin());
		Y.erase(Y.begin());
		if (mp.count(X)==0)
		{
			mp[X].diem=0;
			mp[X].hieuso=0;
		}
		if (mp.count(Y)==0)
		{
			mp[Y].diem=0;
			mp[Y].hieuso=0;
		}
		if (x>y) mp[X].diem+=3;
		else 
		if (y>x) mp[Y].diem+=3;
		else {
			mp[X].diem++;
			mp[Y].diem++;
		}
		mp[X].hieuso+=(x-y);
		mp[Y].hieuso+=(y-x);
		for (pair<string,mang> k : mp) v.push_back(k);
		sort(v.begin(),v.end(),cmp);
		for (pair<string,mang> k : mp)
		cout<<k.first<<" "<<k.second.diem<<" "<<k.second.hieuso<<endl;
	}
}
