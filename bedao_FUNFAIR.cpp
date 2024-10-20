#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
int a[maxn],x,y,n;
void input()
{
    cin>>n>>x>>y;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
}
bool check(int k)
{
    return (k>=x && k<=y);
}
void process()
{
    ll res=0,sum=0,l=1,rl,rr;
    int r=0;
    while (r<n)
    {
        cout<<l<<" "<<r<<" "<<sum<<endl;
        r++;
        if (check(a[r])) 
        {
            sum+=a[r];
            if (sum>res)
            {
                res=sum;
                rr=r;
                rl=l;
            }
            if (sum<0)
            {
                sum=0;
                l=r;
            }
        }
        else 
        {
            sum=0;
            l=r;
        }
    }
    cout<<res<<"\n";
    cout<<rl<<" "<<rr;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

