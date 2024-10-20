#include <bits/stdc++.h>
using namespace std;
void process(string x,string y)
{
	int n=x.length()-1;
	int res=0;
	for (int i=0;i<=n;i++)
	{
		if (x[i]!='?' && x[i]>y[i])
		{
			int cnt=0;
			for (int j=i;j<=n;j++) 
				if (x[j]=='?') cnt++;
			res+=pow(10,cnt);
			cout<<res<<endl;
			return;
		}
		else
		if (x[i]=='?')
		{
			int tmp=(9-(y[i]-'0'));
			int cnt=0;
			for (int j=i+1;j<=n;j++)
				if (x[j]=='?') cnt++;
			res+=tmp*pow(10,cnt);
			continue;
		} 
		else 
		if (x[i]!='?' && x[i]==y[i]) continue;
		else
		if (x[i]!='?' && x[i]<y[i]) 
		{
			cout<<res<<endl;
			return;
		}
	}
	cout<<res<<endl;
}
int main()
{
	freopen("thu.inp","r",stdin);
	string x,y;
	while (cin>>x)
	{
		if (x=="#") return 0;
		cin>>y;
		process(x,y);
	}
}
