#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 500005
int n,s1=0,s2=0;
pair<int,int> a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
        s1+=a[i].first;
        s2+=a[i].second;
    }
    if (s1%2 == s2%2 && s1%2) cout<<"1";
    else 
    if (s1%2 == s2%2 && s1%2==0) cout<<"0";
    else 
    cout<<"-1";
}

