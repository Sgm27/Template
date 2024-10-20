#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 
map<int,int> mp;
bool nto(int k)
{
    if (k==2 || k==3) return 1;
    if (k<2 || k%2==0 || k%3==0) return 0;
    int i=5;
    while (i<=sqrt(k))
    {
        if (k%i==0 || k%(i+2)==0) return 0;
        i+=6;
    }
    return 1;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    int i=2;
    while (n!=1)
    {
        if (nto(n)) mp[n]++, n=1;
        while (n%i==0) n/=i, mp[i]++;
        i++;
    }
    for (pii x : mp) cout<<x.first<<" "<<x.second<<"\n";
}
