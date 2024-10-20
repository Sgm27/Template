#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,k,a[1000005];
void process()
{
    stack<ll> S;
    ll res1=0,res2=0;
    int i=0;
    while (i<n)
    {
        if (S.empty() || a[i]>=a[S.top()])
        {
            S.push(i);
            i++;
        }
        else{
            int idx=S.top();
            S.pop();
            if (S.empty())
                res1=max(res1,i*a[idx]);
            else
                res1=max(res1,a[idx]*(i-S.top()-1));
        }
    }
    while (!S.empty())
    {
        int idx=S.top();
        S.pop();
        if (S.empty())
            res1=max(res1,i*a[idx]);
        else
            res1=max(res1,a[idx]*(i-S.top()-1));
    }
    for (int i=0;i<=n;i++) a[i]=k-a[i];
    i=0;
    while (i<n)
    {
        if (S.empty() || a[i]>=a[S.top()])
        {
            S.push(i);
            i++;
        }
        else{
            int idx=S.top();
            S.pop();
            if (S.empty())
                res2=max(res2,i*a[idx]);
            else
                res2=max(res2,a[idx]*(i-S.top()-1));
        }
    }
    while (!S.empty())
    {
        int idx=S.top();
        S.pop();
        if (S.empty())
            res2=max(res2,i*a[idx]);
        else
            res2=max(res2,a[idx]*(i-S.top()-1));
    }
    cout<<max(res1,res2);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>k>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    process();
}

