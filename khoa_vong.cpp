#include <bits/stdc++.h>
using namespace std;
int n;
string s1,s2;
void input()
{
	cin>>n;
	cin>>s1>>s2;
}
void process()
{
	long long res=0;
	for (int i=0;i<=n-1;i++)
	{
		int tmp1=s1[i]-'0';
		int tmp2=s2[i]-'0';
		res+=min(abs(tmp1-tmp2),10-max(tmp1,tmp2)+min(tmp1,tmp2));
	}
	cout<<res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
