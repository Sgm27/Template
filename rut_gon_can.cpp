#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e9;
map<int,int> mp;
void sang()
{
    for (int i=2;i<=sqrt(N);i++) 
        for (int j=i*i;j<=N;j+=i*i) mp[j]=i; 
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    sang();
    int tc; cin>>tc;
    while (tc--)
    {
        int n,x;
        cin>>n;
        x=mp[n];
        cout<<x<<" "<<n/(x*x)<<"\n";
    }

}

