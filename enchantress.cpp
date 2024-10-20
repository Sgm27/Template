#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a,b,c;
void process()
{
    if (a==0 && (b==0 || c==0))
    {
        cout<<"NO\n";
        return;
    }
    int tmp=max(b,c)-min(b,c);
    if (tmp%3==0) 
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>a>>b>>c;
        process();	
    }
}

