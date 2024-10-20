#include <bits/stdc++.h>
using namespace std;
int n;
string s1,s2,ans;
string tron(string a,string b)
{
	string res="";
	int i=0,j=0;
	while (i<=n-1)
	{
		if (i==j)
		{
			res+=b[j];
			j++;
		}
		else
		{
			res+=a[i];
			i++;
		}
	}
	return res;
}
void process()
{
	int cnt=0;
	string tmp1=s1,tmp2=s2;
	while (1)
	{
		string tmp=tron(tmp1,tmp2);
		if (tmp==ans)
		{
			cout<<cnt+1<<endl;
			return;	
		} 
		if (cnt>50) 
		{
			cout<<"-1\n";
			return;
		}
		tmp1=tmp.substr(0,n);
		tmp2=tmp.substr(n,n);
		cnt++;
	}
	cout<<cnt<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	while (cin>>n)
	{
		if (!n) return 0;
		cin>>s1>>s2>>ans;
		process();	
	}	
}
