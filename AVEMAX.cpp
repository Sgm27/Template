#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,Max=INT_MIN;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        Max=max(Max,x);
    }
    cout<<Max;
}

