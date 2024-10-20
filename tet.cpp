// cap so co tong bang k
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return (a.first<b.first);
}
int main()
{
    freopen("son.inp","r",stdin);
    int n; cin>>n;
    vector<pair<int,int>> v(n+1);
    for (int i=1;i<=n;i++)
    {
        cin>>v[i].first;
        int x; cin>>x;
        v[i].second=v[i].first+x;
    }
    //sort(begin(v)+1,begin(v)+n+1,cmp);
    sort(v.begin()+1,v.begin()+n+1,cmp);
   // for (int i=1;i<=n;i++)
    //    cout<<v[i].first<<" "<<v[i].second<<endl;
    for (int i=2;i<=n;i++)
    {
        if (v[i].first<v[i-1].second)
        {
            v[i].second=v[i-1].second+v[i].second-v[i].first;
            v[i].first=v[i-1].second;
        }
    }
    cout<<v[n].second<<endl;
    return 0;
}


