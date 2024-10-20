#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int a[maxn];
vector<int> res;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int idx=1,id=1;
    while (m>0)
    {
        if (a[id]!=idx) 
        {
            if (m>=idx) m-=idx;
            else break;
            res.push_back(idx);
            idx++;
            continue;
        }
        if (a[id]==idx) idx++, id++;
        else id++;
    }
    cout<<res.size()<<"\n";
    for (int x : res) cout<<x<<" ";
}

