#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
#define maxn 
int process(string s)
{
    int n=s.length()-1,cnt0=0;
    int st=0,ed=n;
    while (st<=n && s[st]=='0') st++;
    if (st>n) 
    {
        return 0;
    }
    while (ed>st && s[ed]=='0') ed--;
    for (int i=st;i<=ed;i++) 
        if (s[i]=='0') cnt0++;
    int res=cnt0,sl1=0,sl0=0,it=0,sl0_max=0,sl1_max=0;
    for (int i=st;i<=ed;i++)
    {
        if (s[i]=='0') sl0++;
        else sl1++;
        if (max(cnt0-sl0,sl1)<res)
        {
            res=max(cnt0-sl0,sl1);
            sl0_max=sl0;
            sl1_max=sl1;
            it=i;
        }
    }
    sl0=sl0_max;
    sl1=sl1_max;
    for (int i=ed;i>it;i--)
    {
        if (s[i]=='0') sl0++;
        else sl1++;
        if (max(cnt0-sl0,sl1)<res)
        {
            res=max(cnt0-sl0,sl1);
        }
    }
    return res;
}
int main()
{
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        cout<<min(process(s),process(t))<<"\n";	
    }
}

