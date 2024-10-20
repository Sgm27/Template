#include <bits/stdc++.h>
using namespace std;
int d[260];
bool check(string a,string b)
{
	for (int i=97;i<=122;i++) d[i]=0;
	for (int i=0;i<a.length();i++) d[a[i]]++;
	for (int i=0;i<b.length();i++) d[b[i]]--;
	for (int i=97;i<=122;i++) 
		if (d[i]) return false;
	return true;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	string x,y;
	int tt=0;
	while (cin>>x>>y)
	{
		tt++;
		if (x=="END" && y=="END") return 0;
		cout<<"Case "<<tt<<": ";
		if (check(x,y)) cout<<"same\n";
		else cout<<"different\n";
	}
}
