#include <bits/stdc++.h>
using namespace std;
int n,tt=0;
string a[25];
bool cmp(string a,string b)
{
	if (a.length()!=b.length()) return a.length()<b.length();
	return a<b;
}
void chuanhoa()
{
	for (int i=1;i<=n;i++) 
		while (a[i][0]=='0') a[i].erase(a[i].begin());
}
void process()
{
	cout<<"Case "<<tt<<": ";
	sort(a+1,a+1+n,cmp);
	bool check=false;
	for (int i=1;i<=n-1;i++) 
		if (a[i]!=a[i+1]) 
		{
			check=true;
			break;
		}
	if (!check) cout<<"There is a row of trees having equal height.\n";
	else cout<<a[1]<<" "<<a[n]<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	while (cin>>n)
	{
		tt++;
		if (n==0) return 0;
		for (int i=1;i<=n;i++) cin>>a[i];
		chuanhoa();
		process();
	}
}
