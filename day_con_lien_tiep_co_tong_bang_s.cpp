#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int n;
ll a[100005],s[100005],k;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int check=0;
        cin>>n>>k;
        s[0]=0;
        for (int i=1;i<=n;i++) 
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        for (int i=1;i<=n;i++)
            if (binary_search(s+i,s+1+n,s[i-1]+k)) 
            {
                check=1;
                break;
            }
        if (check) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

