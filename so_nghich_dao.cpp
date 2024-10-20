#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("thu.inp","r",stdin);
	string a,b;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	cout<<max(stoll(a),stoll(b));
}
