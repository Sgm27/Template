#include <bits/stdc++.h>
using namespace std;
int n,a[105][105];
string dp[105][105];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
}
void init()
{
	for (int i=1;i<=n;i++)
	{
		dp[0][i]="";
		dp[i][0]="";
	}
}
void in()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) cout<<dp[i][j];
		cout<<endl;
	}
}
string qhd()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			dp[i][j]="";
			dp[i][j]=max(dp[i][j-1],dp[i-1][j])+(char)(a[i][j]+'0');
		}
	return dp[n][n];
}
void truy_vet()
{
	long long sum=0,hai=1;
	string res=qhd();
	reverse(res.begin(),res.end());
	for (char x : res)
	{
		sum+=(x-'0')*hai;
		hai*=2;
	}
	string result="";
	while (sum)
	{
		int tmp=sum%16;
		sum/=16;
		if (tmp<10) result=(char)(tmp+'0')+result;
		else 
		{
			if (tmp==10) result="A"+result;
			if (tmp==11) result="B"+result;
			if (tmp==12) result="C"+result;
			if (tmp==13) result="D"+result;
			if (tmp==14) result="E"+result;
			if (tmp==15) result="F"+result;
		}
	}
	cout<<result;
}
string BinToHex(string x)
{
    string rs = "";
    while (x.size()%4!=0)
        x="0"+x;
    
    for (int i=0; i<x.size(); i=i+4)
    {
        string tmp = x.substr(i, 4);
        int d = 0;
        for (int j=0; j<4; j++)
        {
            d+=((tmp[j]-'0')*pow(2,(3-j)));
        }
        char c;
        if (d>=0 && d<=9)
            c = d+'0';
        else
            c = d-10+'A';
        rs = rs+c;
    }
    if (rs=="") return "0";
    else
    {
        while (1)
        {
            if (rs.size()-1==0 || rs[0]!='0') break;
            rs.erase(rs.begin(), rs.begin()+1);
        }
    }
    return rs;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	init();
	cout<<BinToHex(qhd());
}
