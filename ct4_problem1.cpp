#include <bits/stdc++.h>
using namespace std;
int prime[1000005],cnt[1000005];
void sang()
{
	const int N=1000000;
	for (int i=1;i<=N;i++) prime[i]=1;
	prime[0]=0;
	prime[1]=0;
	for (int i=2;i<=1000;i++)
		if (prime[i]) 
			for (int j=i*i;j<=N;j+=i) prime[j]=0;
}
void process()
{
	sang();
	cnt[0]=0;
	for (int i=1;i<=1000000;i++) 
		if (prime[i]) cnt[i]=cnt[i-1]+1;
		else cnt[i]=cnt[i-1];
}
int main()
{
	//freopen("thu.inp","r",stdin);
	process();
	int tc;
	cin>>tc;
	while (tc--)
	{
		int l,r;
		cin>>l>>r;
		cout<<cnt[r]-cnt[l-1]<<endl;
	}
}
