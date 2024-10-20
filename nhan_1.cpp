#include <bits/stdc++.h>
using namespace std;
void process(int n)
{
	int tmp=(n-1)/9;
	for (int i=1;i<=tmp;i++) cout<<"123456790";
	int tmp2=(n-1)%9;
	for (int i=1;i<=tmp2;i++) cout<<i;
	for (int i=tmp2+1;i>=2;i--) cout<<i;
	for (int i=1;i<=tmp;i++) cout<<"098765432";
	cout<<"1"<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		process(n);
	}
}
