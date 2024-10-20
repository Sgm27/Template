#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
ll a,b,n;
int moda[1000000],modb[1000000];
void input()
{
	cin>>s>>a>>b;
	n=s.length();
	s="#"+s;
}
void process()
{
	moda[0]=0;  
	for (int i=1;i<=n;i++)
	{
		moda[i]=(moda[i-1]*10+(s[i]-'0'))%a;
	}
	ll tmp=1;
	modb[n+1]=0;
	for (int i=n;i>=1;i--)
	{
		tmp*=10; tmp%=b;
		modb[i]=(modb[i+1]+(s[i]-'0')*tmp)%b;
	}
	for (int i=1;i<=n;i++)
		if (moda[i]==0 && modb[i+1]==0 && s[i+1]!='0')
		{
			if (i==n) break;
			cout<<"YES\n";
			cout<<s.substr(1,i)<<endl<<s.substr(i+1,n-i);
			return;
		}
	cout<<"NO";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}

