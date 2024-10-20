#include <bits/stdc++.h>
using namespace std;
struct sv{
	string name;
	double gpa;
	friend operator > (const sv a,const sv b)
	{
		return a.gpa>b.gpa;
	}
};
int main()
{
	freopen("son.inp","r",stdin);
	int n;
	cin>>n;
	sv ds[n];
	for (sv &x : ds)
	{
		cin>>x.gpa;
		cin.ignore();
		getline(cin,x.name);
	}
	sort(ds,ds+n,greater<sv>());
	for (sv x : ds)
	{
		cout<<x.name<<" "<<x.gpa<<endl;
	}
}
