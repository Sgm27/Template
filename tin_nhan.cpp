#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc>=0)
	{
		string s;
		getline(cin,s);
		stringstream ss(s);
		string tmp,nan,res="";
		while (ss >> tmp)	res+=tmp;
		strncpy(nan,res,);
		string cc=tolower(nan)+"ee";
		cout<<cc<<endl;
		//res+=cc;
		//res.erase(0,1);
	//	cout<<res<<endl;
		//cout<<" "<<(char)tolower(res[0])<<endl;
		tc--;
	}
}
