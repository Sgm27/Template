#include<iostream>
using namespace std;
using ll = long long;
string s;
void process()
{
    ll res=0;
    int tmp;
    if ((s[0]-'0')%4==0) res++;
    for (int i=1;i<s.length();i++)
    {
        if ((s[i]-'0')%4==0) res++;
        tmp=(s[i]-'0')+(s[i-1]-'0')*10;
        if (tmp%4==0) res+=i;
    }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    process();
}

