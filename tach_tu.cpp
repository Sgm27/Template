#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 205
string a,b,c;
int n;
bool check = false;
void Try(int i,int j,int k,string ans)
{
	if (check) return;
	if (i == n) 
	{
		cout<<ans;
		check = true;
		return;
	}
	if (a[j] == c[i]) Try(i+1,j+1,k,ans+'1');
	if (b[k] == c[i]) Try(i+1,j,k+1,ans+'2');
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>a>>b>>c;
	n = c.length();
	Try(0,0,0,"");
}
