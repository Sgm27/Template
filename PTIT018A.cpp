#include <bits/stdc++.h>
using namespace std;
int prime[1000005];
void sang()
{
	for (int i=0;i<=1000000;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=2;i<=1000;i++)
		if (prime[i])
			for (int j=i*i;j<=1000000;j+=i) prime[j]=0;
}
int main()
{
	sang();
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		int l,r;
		cin>>l>>r;
		int cnt=0;
		for (int i=l;i<=r-6;i++) 
			if (prime[i] && prime[i+6]) cnt++;
		cout<<cnt<<endl;
	}
}
