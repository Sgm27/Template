#include <bits/stdc++.h>
using namespace std;
int n,sum=0;
void input()
{
	cin>>n;
}
void process()
{
	for (int i=1;i<=n;i++) sum+=i;
	cout<<sum;
}
int main()
{
	input();
	process();
}