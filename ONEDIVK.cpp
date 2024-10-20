#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
bool bigmod(string s,int x)
{
	int res=0;
	for (char k : s)
	{
		res=(res*10+(k-'0'))%x;
	}
	return res==0;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int k;
    bool flag=false;
    string s=""; cin>>k;
    int res=1,step=1;
    if (k==1) return cout<<1, 0;
    while (res!=0 && step<1e7)
    {
        res=(res*10+1)%k;
        ++step;
    }
    if (step<1e7) cout<<step;
    else cout<<"-1";
}

