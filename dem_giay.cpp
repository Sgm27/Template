#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	int Max=max(n,m);
	int Min=min(n,m);
	cout<<Min<<" "<<(Max-Min)/2;
}
