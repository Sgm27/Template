#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,k,ans[maxn];
pair<int,int> a[maxn];
void process()
{
    deque<int> dq;
    for (int i=1;i<=n;i++)
    {
        while (!dq.empty() && a[i].first<a[dq.back()].first) dq.pop_back();
        dq.push_back(i);
        while (!dq.empty() && a[i].second-k>=a[dq.front()].second) dq.pop_front();
        if (!dq.empty() && i>=k) ans[i]=dq.front();
    }
    for (int i=k;i<=n;i++) cout<<a[ans[i]].first<<" ";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i].first, a[i].second=i;
    process();
}

