#include <bits/stdc++.h>
using namespace std;
string in_val="";
using ll = long long;
ll a[300000],dem=0,n=1;
void thu(int i)
{
	for (int j=0;j<=1;j++)
	{
		if (j==0) in_val+="6";
		else in_val+="8";
		if (i==n) a[++dem]=stoll(in_val);
		else thu(i+1);
		in_val.pop_back();
	}
}
void process()
{
	while (n<=17)
	{
		thu(1);
		n++;
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	process();
	int tc=0;
	cin>>tc;
	while (tc--)
	{
		ll x,y;
		cin>>x>>y;
		int tmp1=lower_bound(a+1,a+dem+1,x)-a;
		int tmp2=upper_bound(a+1,a+dem+1,y)-a;
		while (a[tmp2]>y) tmp2--;
		cout<<tmp2-tmp1+1<<endl;
	}
}

