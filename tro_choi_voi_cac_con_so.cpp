#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x,a,b,d[15],n=0,res=0;
set<ll> se;
void input()
{
	cin>>x>>a>>b;
	string s;
	cin>>s;
	for (char x : s) d[++n]=x-'0';
}
void process()
{
	queue<ll> Q;
	Q.push(0);
	while (!Q.empty())
	{
		ll tmp=Q.front();
		Q.pop();
		for (int i=1;i<=n;i++)
		{
			ll k;
			k=tmp*10+d[i];
			if (k>b) return;
			Q.push(k);
			if (k%x==0 && k>=a && k<=b && !se.count(k)) 
			{
				res++;
				se.insert(k);
			}
		}
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
	cout<<res;
}

