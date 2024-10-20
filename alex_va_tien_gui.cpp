#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll Max;
string s;
void input()
{
	cin>>s;
}
void process()
{
	string tmp1=s;
	tmp1.erase(tmp1.end()-1);
	string tmp2=s;
	tmp2.erase(tmp2.end()-2);
	Max=max(stoll(tmp1),max(stoll(tmp2),stoll(s)));
	cout<<Max;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
