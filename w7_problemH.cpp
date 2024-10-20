#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
#define maxn 10004
int n,k,a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        if (n<3 || a[1]+a[2]+a[3]>k || a[n]+a[n-1]+a[n-2]<k) 
        {
            cout<<"NO\n";
            continue;
        }
        bool flag=false;
        for (int i=1;i<=n-2;i++)
        {
            int l=i+1,r=n,sum=k-a[i];
            while (l<r)
            {
                if (a[l]+a[r]==sum) 
                {
                    cout<<"YES\n";
                    flag=true;
                    break;
                }
                else
                if (a[l]+a[r]<sum) l++;
                else r--;
            }
            if (flag) break;
        }	
        if (!flag) cout<<"NO\n";
    }
}

