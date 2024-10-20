#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<int> cp;
void input()
{
	cin>>n;
}
void process()
{
	for (int i=1;i<=sqrt(n);i++) cp.push_back(i*i);
	reverse(cp.begin(),cp.end());
	for (int x : cp)
		while (n && n>=x)
		{
			n-=x;
			cout<<sqrt(x)<<" ";
		}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("thu.inp","r",stdin);
	input();
	process();
}

