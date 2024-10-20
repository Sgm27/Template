#include <bits/stdc++.h>
using namespace std;
int n,prime[3005];
void input()
{
	cin>>n;
}
void sang()
{
	const int N=3000;
	for (int i=1;i<=N;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=2;i<=sqrt(N);i++)
		if (prime[i])
			for (int j=i*i;j<=N;j+=i) prime[j]=0;
}
bool check(int n)
{
	int cnt=0;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0)
		{
			if (prime[i]) cnt++;
			if (n/i!=i && prime[n/i]) cnt++;
			if (cnt>2) return false;
		}
	return cnt==2;
}
void process()
{
	int res=0;
	for (int i=1;i<=n;i++) 
		if (check(i)) res++;
	cout<<res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	sang();
	input();
	process();
}
