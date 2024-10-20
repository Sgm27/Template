#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll l,r,Nx,res=0;
queue<ll> Q;
void input()
{
    cin>>l>>r;
    Nx=l;
}
void process()
{
    bool check_update=0;
    bool ok=true;
    Q.push(0);
    ll x;
    while (1)
    {
        ll tmp=Q.front();
        Q.pop();
        x=tmp*10+4;
        if (x>r) 
        {
            if (!check_update) 
            {
                res+=(r-l+1)*x;
                return;
            }
            res+=(r-Nx)*x;
            return;
        }
        Q.push(x);
        if (x>=l && x<=r) 
        {
            if (ok) 
            {
                res+=x*(x-Nx+1);
                check_update=1;
                ok=false;
            }
            else 
            {
                res+=x*(x-Nx);
                check_update=1;
            }
            Nx=x;
        }
        x=tmp*10+7;
        if (x>r) 
        {
            if (!check_update) 
            {
                res+=(r-l+1)*x;
                return;
            }
            res+=(r-Nx)*x;
            return;
        }
        Q.push(x);
        if (x>=l && x<=r) 
        {
            if (ok) 
            {
                res+=x*(x-Nx+1);
                check_update=1;
                ok=false;
            }
            else 
            {
                res+=x*(x-Nx);
                check_update=1;
            }
            Nx=x;
        }
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
    cout<<res;
}

