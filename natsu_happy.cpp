#include <bits/stdc++.h>
using namespace std;
bool cp(int n)
{
	int tmp=sqrt(n);
	if (tmp*tmp==n) return 1;
	return 0;
}
int process(int n)
{
	int cnt=0;
	for (int i=1;i<=sqrt(n);i++)
		if (n%i==0)
		{
			if (i%2==0) cnt++;
			if ((n/i)%2==0) cnt++;
		}
	if (cp(n) && ((int)(sqrt(n))%2==0)) cnt--;
	return cnt;
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		cout<<process(n)<<endl;
	}
}
