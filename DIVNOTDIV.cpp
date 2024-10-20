#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int a,b; ll n;
        cin>>a>>b>>n;
        if (a%b==0) 
        {
            cout<<"-1\n";
            continue;
        }
        else
        {
            ll tmp=((n/a)+(n%a!=0))*a;
            while (1)
            {
                if (tmp%b==0) tmp+=a;
                else 
                {
                    cout<<tmp<<"\n";
                    break;
                }
            }
        }
    }
}

