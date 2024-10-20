#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,x,a[1000005];
void input()
{
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
    int cnt=1,Min=1e9,val;
    sort(a+1,a+1+n);
    a[n+1]=-1;
    for (int i=1;i<=n;i++)
        if (a[i]==a[i+1]) cnt++;
        else
        {
            if (cnt<Min) 
            {
                Min=cnt;
                val=a[i];
            }
            else 
            if (cnt==Min && a[i]>val) val=a[i];
            cnt=1;
        }
    cout<<1ll*n*x-1ll*Min*val;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

