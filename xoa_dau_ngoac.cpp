#include <bits/stdc++.h>
using namespace std;
string s;
int cnt=0,x[15],in_val;
bool check[15],d[205];
vector<string> res;
void input()
{
	cin>>s;
}
struct mang{
	int op,cl;
};
mang a[15];
void init()
{
	stack<int> S;
	for (int i=0;i<s.length();i++)
		if (s[i]=='(') S.push(i);
		else 
			if (s[i]==')')
			{
				cnt++;
				a[cnt].op=S.top();
				a[cnt].cl=i;
				S.pop();
			}
}
void xulycauhinh(int n)
{
	for (int i=1;i<=n;i++)
	{
		d[a[x[i]].op]=false;
		d[a[x[i]].cl]=false;
	}
	string tmp="";
	for (int i=0;i<s.length();i++) 
		if (d[i]) tmp+=s[i];
	res.push_back(tmp);
	for (int i=1;i<=n;i++)
	{
		d[a[x[i]].op]=true;
		d[a[x[i]].cl]=true;
	}
}
void thu(int i)
{
	for (int j=1;j<=cnt;j++)
		if (check[j])
		{
			x[i]=j;
			check[j]=false;
			if (i==in_val)
			{
				xulycauhinh(in_val);
			}
			else thu(i+1);
			check[j]=true;
		}
}
void process()
{
	for (int i=0;i<s.length();i++) d[i]=true;
	in_val=1;
	while (in_val<=cnt)
	{
		for (int i=1;i<=cnt;i++) check[i]=true;
		thu(1);
		in_val++;
	}
	sort(res.begin(),res.end());
	cout<<res[0]<<endl;
	for (int i=1;i<res.size();i++) 
		if (res[i]!=res[i-1]) cout<<res[i]<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	init();
	process();
}
// toi uu
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
long a[20], b[20], st[20], n, t;
long x[20], xh[201];
long l;
string rs[2049];
long r = 0;

void update()
{
	for (long i = 0; i < l; i++) xh[i] = 1;
	for (long i = 1; i <= n; i++)
	  if (x[i] == 0)
	  {
	  	xh[a[i]] = 0;
	  	xh[b[i]] = 0;
	  }
	r++;
	rs[r] = "";
	for (long i = 0; i < l; i++) 
	  if (xh[i]) rs[r] += s[i];
}

void Try(long i)
{
	for (long j = 0; j <= 1; j++)
	{
		x[i] = j;
		if (i == n) update();
		else Try(i + 1);
	}
}
main()
{
	//freopen("thu.inp","r",stdin);
	cin >> s;
	n = 0;
	t = 0;
	l = s.length();
	for (long i = 0; i < l; i++)
	  if (s[i] == '(')
	  {
	  	t++;
	  	st[t] = i;
	  }
	  else
	  if (s[i] == ')')
	  {
	  	n++;
	  	a[n] = st[t];
	  	b[n] = i;
	  	t--;
	  }
	Try(1);
	r--;
	sort(rs + 1, rs + 1 + r);
	rs[0] = "*";
	for (long i = 1; i <= r; i++) 
	  if (rs[i] != rs[i - 1]) cout << rs[i] << endl;
}
