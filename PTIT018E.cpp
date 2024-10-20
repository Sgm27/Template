#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 25
#define bit(i,n) ((n>>i)&1)
int n,a[maxn],sum;
vector<int> v;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        for (int i=0;i<n;i++) cin>>a[i];
        for (int mask=1;mask<(1<<n);mask++)
        {
            sum=0;
            for (int i=0;i<n;i++) 
                if (bit(i,mask)) sum+=a[i];
            v.push_back(sum);
        }
        int max_size=v.size();
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        if (v.size()<max_size) cout<<"YES\n";
        else cout<<"NO\n";
        v.clear();
    }
}

