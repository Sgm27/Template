#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> v;
int n,k,x[15],res=1e9;
bool d[15];
void input()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) 
    {
        string s;
        cin>>s;
        s="#"+s;
        v.push_back(s);
    }
}
void xuly()
{
    int Max=-1,Min=1e9;
    for (string s : v)
    {
        int tmp=0;
        for (int i=1;i<=k;i++)  tmp=tmp*10+(s[x[i]]-'0');
        Max=max(Max,tmp);
        Min=min(Min,tmp);
    }
    res=min(res,Max-Min);
}
void Try(int i)
{
    for (int j=1;j<=k;j++)
        if (d[j])
        {
            d[j]=false;
            x[i]=j;
            if (i==k) xuly();
            else Try(i+1);
            d[j]=true;
        }
}
int main()
{
    memset(d,true,sizeof(d));
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    Try(1);
    cout<<res;
}

