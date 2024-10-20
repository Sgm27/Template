#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a,b,c,sum[1000005];
const ll MOD=1073741824;
void input()
{
	cin>>a>>b>>c;
}
void sang()
{
	const ll N=1000005;
	for (int i=1;i<=N;i++) sum[i]=0;
	for (int i=1;i<=sqrt(N);i++)
		for (int j=i*i;j<=N;j+=i)
		{
			sum[j]++;
			if (i!=j/i) sum[j]++;
		}
}
void process()
{
	ll res=0;
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++) 
			for (int k=1;k<=c;k++) res=(res+sum[i*j*k])%MOD;
	cout<<res%MOD;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	sang();
	process();
}
