#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int n;
string s;
void process(string s)
{
	int idx=0,res=n-1;
	while (idx<=n-1)
	{
		bool check=false;
		int st=idx;
		while (idx<n-1 && s[idx]==s[idx+1]) 
		{
			idx++;
			check=true;
		}
		int sl=idx-st+1;
		if (sl>=3) res-=(sl-2);
		if (check) continue;
		st=idx;
		check=false;
		while (idx+2<=n-1 && s[idx]==s[idx+2]) 
		{
			idx++;
			check=true;
		}
		if (check) 
		{
			idx+=1;
			sl=idx-st+1;
			res-=(sl-2);
			continue;
		}
		idx++;
	}
	cout<<res<<"\n";
}
int main()
{
	// freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc; cin>>tc;
	while (tc--)
	{
		cin>>n>>s;
		process(s);	
	}	
}

