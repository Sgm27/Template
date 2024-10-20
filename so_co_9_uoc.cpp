#include <bits/stdc++.h>
using namespace std;
int n,prime[16000],dem;
int nto[2000];
void input()
{
	cin>>n;
}
void sang()
{
	const int N=16000;
	for (int i=1;i<=N;i++) prime[i]=1;
	prime[1]=0; prime[0]=0;
	for (int i=1;i<=sqrt(N);i++)
		if (prime[i])
			for (int j=i*i;j<=N;j+=i) prime[j]=0;
	dem=0;
	for (int i=1;i<=N;i++)
	{
		if (prime[i])
		{
			dem++;
			nto[dem]=i;
		}
	}
}
void process()
{
	int tmp=(int)(pow(n,1.0/8));
	int res=0;
	for (int i=2;i<=tmp;i++) if (prime[i]) res++;
	for (int i=6;i<=sqrt(n);i++)
	{
		int k=1,x=sqrt(i);
		while (1)
		{
			if (nto[k]>x) break;
			if (i%nto[k]==0)
			{
				if (prime[i/nto[k]] && nto[k]!=i/nto[k]) 
				{
					res++;
					break;
				}
				else k++;
			}
			else k++;
		}
	}
	cout<<res;
}
int main()
{
	input();
	sang();
	process();
	return 0;
}
