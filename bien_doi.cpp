#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
const int N=1e6;
pair<int,int> ans[maxn];

void sang()
{
    for (int i=1;i<=N;i++) ans[i]={i,0};
    for (int i=2;i<=sqrt(N);i++) ans[i*i]={ans[i].first,ans[i].second+1};
    for (int i=2;i<=sqrt(N);i++)
        for (int j=i*i;j<=N;j+=i)
        {
            if (ans[i].first<ans[j].first) 
                ans[i]={ans[j].first,ans[j].second+1};
        }
}
int main()
{
    freopen("thu.inp","r",stdin);
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    sang();
    int n; cin>>n;
    cout<<ans[n].first<<" "<<ans[n].second;
}

