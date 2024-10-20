#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
map<string,int> mp;
string a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i], mp[a[i]]++;
    for (int i=1;i<=n;i++) 
        if (mp[a[i]]%2) 
            return cout<<a[i], 0;
    cout<<"-1";
}

