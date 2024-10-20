#include<iostream>
using namespace std;
long long n,m;
long long source(long long k)
{
	if (k<=n) return n-k;
	return source((k+1)/2)+1+k%2;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m;
	cout<<source(m);
}

