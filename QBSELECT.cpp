#include<iostream>
using namespace std;
using ll = long long;
#define maxn 10005
int n,a[5][maxn],dp[maxn][16],res=-1e9;
void input()
{
	cin>>n;
	for (int i=1;i<=4;i++)
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			res=max(res,a[i][j]);
		}
}
int check(int x)
{
	if (x==3 || x==6 || x==7 || x>=11) return 0;
	return 1;
}
int get_val(int i,int x)
{
	int sum=0;	
	for (int j=0;j<4;j++)
		if ((x>>j)&1) sum+=a[j+1][i];
	return sum;
}
void process()
{
	if (res<=0)
	{
		cout<<res;
		return;
	}
	for (int i=1;i<=n;i++)
		for (int x=0;x<16;x++)
			if (check(x))
			{
				int T=get_val(i,x);
				dp[i][x]=-1e9;
				for (int z=0;z<16;z++)
					if (check(z) && (x&z)==0) dp[i][x]=max(dp[i][x],dp[i-1][z]+T);
			}
	for (int i=0;i<16;i++) 
		if (check(i)) res=max(res,dp[n][i]);
	cout<<res;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	input();
	process();
}

