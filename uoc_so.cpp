#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
using ll = long long;
int cnt[N]={},sum[N]={},res_sum[N],res_cnt[N];
bool cp(int k)
{
	int tmp=sqrt(k);
	return tmp*tmp==k;
}
void sang_uoc()
{
	for (int i=1;i<=sqrt(N);i++)
		for (int j=i*i;j<=N;j+=i)
		{
			cnt[j]++;
			sum[j]+=i;
			if (i!=j/i) 
			{
				sum[j]+=j/i;	
				cnt[j]++;
			}
		}
}
void init()
{
	res_sum[0]=0;
	res_cnt[0]=0;
	for (int i=1;i<=N;i++) 
		{
			res_sum[i]=res_sum[i-1]+sum[i];
			res_cnt[i]=res_cnt[i-1]+cnt[i];
		}
}
int main()
{
	// freopen("thu.inp","r",stdin);
	sang_uoc();
	init();
	int tc; cin>>tc;
	while (tc--)
	{
		int a,b;
		cin>>a>>b;
		cout<<res_cnt[b]-res_cnt[a-1]<<" "<<res_sum[b]-res_sum[a-1]<<endl;
	}
}
