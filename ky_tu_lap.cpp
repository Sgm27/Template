#include <bits/stdc++.h>
using namespace std;
int n,Min=INT_MAX,x[15];
string a[15];
bool d[15];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
}
int dem(string a,string b)
{
	int cnt=0;
	for (int i=0;i<a.length();i++)
		for (int j=0;j<b.length();j++)
			if (a[i]==b[j]) cnt++;
	return cnt;
}
void in()
{
	int res=0;
	for (int i=1;i<=n-1;i++)
		{
			res+=dem(a[x[i]],a[x[i+1]]);
		}
	Min=min(Min,res);
}
void thu(int i)
{
	for (int j=1;j<=n;j++)
		if (d[j])
	{
		x[i]=j;
		d[j]=false;
		if (i==n) in();
		else thu(i+1);
		d[j]=true;
	}
}
int main()
{
	memset(d,true,sizeof(d));
	//freopen("thu.inp","r",stdin);
	input();
	thu(1);
	cout<<Min;
}

