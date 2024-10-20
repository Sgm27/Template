#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
ll l,r;
vector<string> v;
set<ll> se;
string d[10]={"0","1","2","3","4","5","6","7","8","9"},s="";
struct mang{
    ll val,sum;
};
mang a[maxn];
void Try(int i,int n)
{
    int j;
    if (i==1) j=1; else j=0;
    for (j;j<=9;j++)
    {
        s+=d[j];
        if (i==n) v.push_back(s);
        else Try(i+1,n);
        s.pop_back();
    }
}
void process()
{
    for (string x : v)
    {
        string t=x;
        t.pop_back();
        reverse(t.begin(),t.end());
        se.insert(stoll(x+t));
        t=x;
        reverse(t.begin(),t.end());
        se.insert(stoll(x+t));
    }
    int cnt=0;
    for (ll it : se) 
    {
        a[++cnt].val=it;
    }
    ll ans=0;
    for (int i=1;i<=cnt;i++)
        if (a[i].val>=l && a[i].val<=r) ans+=a[i].val;
    cout<<ans;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>l>>r;
    for (int j=1;j<=4;j++)
    {
        s="";
        Try(1,j);
    }
    process();
}

