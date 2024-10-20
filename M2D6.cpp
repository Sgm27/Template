#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 

int process(int n)
{
	int ans=0;
	while (n%6==0 || n%3==0)
	{
		if (n%6==0) n/=6, ans+=1; 
		else n/=3, ans+=2;
	}
	if (n==1) return ans;
	return -1;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc; cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		cout<<process(n)<<"\n";		
	}	
}
