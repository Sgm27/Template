#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int prime[N],cnt[N];
void sang()
{
	vector<int> v;
	memset(prime,1,sizeof(prime));
	memset(cnt,0,sizeof(cnt));
	prime[0]=0; prime[1]=0;
	for (int i=2;i<=sqrt(N);i++)
		if (prime[i])
		 	for (int j=i*i;j<=N;j+=i) prime[j]=0;
	for (int i=2;i<=N;i++) 
		if (prime[i]) v.push_back(i);
	for (int x : v) 
		for (int j=0;j<=N;j+=x) cnt[j]++;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	sang();
	int tc,tt=0;
	cin>>tc;
	while (tc--)
	{
		tt++;
		int res=0;
		int a,b,k;
		cin>>a>>b>>k;
		for (int i=a;i<=b;i++) 
			if (cnt[i]==k) res++;
		cout<<"Case #"<<tt<<": "<<res<<endl;
	}
}
