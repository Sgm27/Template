#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,k,a[maxn],ans[maxn];
void process()
{
    deque<int> dq;
    for (int i=1;i<=n;i++)
    {
        while (!dq.empty() && a[i]>a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        while (!dq.empty() && i-k>=dq.front()) dq.pop_front();
        if (!dq.empty() && i>=k) ans[i]=a[dq.front()];
    }
    for (int i=k;i<=n;i++) cout<<ans[i]<<" ";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    process();
}

