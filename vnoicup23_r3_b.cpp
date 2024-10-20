#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int a,n,b,cnt0,cnt1;
string s;
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cnt0=cnt1=0;
        cin>>n>>a>>b;
        cin>>s;
        for (char x : s)
            if (x=='0') cnt0++;
            else cnt1++;
        int Max=max(cnt0,cnt1);
        if (Max>=a && Max<=a+b && n>=a && n<=a+b) 
        {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}

