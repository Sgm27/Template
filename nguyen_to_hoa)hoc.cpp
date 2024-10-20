#include <bits/stdc++.h>
using namespace std;
string s;
int n;
void input()
{
	cin>>s;
	n=s.length()-1;
}
void process()
{
	stack<int> st;
	int i=0;
	while (i<=n)
	{
		int tong=0;
		if (s[i]=='(') st.push(0);
		if (s[i]=='C') st.push(12);
		if (s[i]=='H') st.push(1);
		if (s[i]=='O') st.push(16);
		if (s[i]==')')
		{
			while (st.top()!=0)
			{
				int x=st.top();
				st.pop();
				tong+=x;
			}
			st.pop();
			st.push(tong);
		}
		if (s[i]>='2' && s[i]<='9') 
		{
			int x=st.top();
			x*=(s[i]-'0');
			st.pop();
			st.push(x);
		}
		i++;
	}
	int res=0;
	while (!st.empty())
	{
		int x=st.top();
		st.pop();
		res+=x;
	}
	cout<<res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
