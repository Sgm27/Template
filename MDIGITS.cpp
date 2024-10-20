#define taskname "cntdigits"
#include <bits/stdc++.h>
#define int long long

using namespace std;
int mu[20];

int cnt(int val, int d)
{
    if (val == 0) return 0;
    vector<int> di;
    int ival = val;
    while (val) di.push_back(val%10), val/=10;
    for (int tmp : di) cout<<tmp<<" "; cout<<"\n";
    int ans = 0, temp = 0;
    for (int pos=0; pos<di.size(); pos++)
    {
        ival/=10;
        cout<<ival<<" "<<pos<<" "<<di[pos]<<"\n";
        if (di[pos] > d) ans += (ival+1-(d==0)) * mu[pos];
        else if (di[pos] == d) ans += (ival-(d==0))*mu[pos] + temp + 1;
        else ans += ival * mu[pos];
        temp = di[pos] * mu[pos] + temp;
        cout<<ans<<"\n";
    }
    return ans;
}

signed main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    mu[0] = 1;
    int x;
    cin>>x;
    for (int i=1; i<=18; i++) mu[i] = mu[i-1] * 10;
    cout<<cnt(x,3)<<"\n";
}
