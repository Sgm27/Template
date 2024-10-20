#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[100005];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=-1000000009;
}
void process()
{
    ll res=1,cnt=1;
    for (int i=1;i<=n;i++)
        if (a[i]<=a[i+1]) cnt++;
        else 
        {
            res=max(res,cnt);
            cnt=1;
        }
    cout<<res;
}
int main()
{
  //  freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

