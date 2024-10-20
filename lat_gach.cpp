#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
string cong(string a,string b)
{
	string res="";
	while (a.length()<b.length()) a="0"+a;
	while (b.length()<a.length()) b="0"+b;
	int nho=0;
	for (int i=a.length()-1;i>=0;i--)
	{
		int tmp=(a[i]-'0')+(b[i]-'0')+nho;
		if (tmp>=10) nho=1;
		else nho=0;
		tmp%=10;
		res=(char)(tmp+'0')+res;
	}
	if (nho) res="1"+res;
	return res;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    vector<string> f(103);
    f[1] = "1", f[2] = "2";
    FOR(i,3,100)
        f[i] = cong(f[i-1] , f[i-2]);
    while (tc--)
    {
        int n; cin>>n;
        cout<<f[n]<<"\n";
    }
}
