#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld=long double;
const ld eps=1e-12;
#define maxn 
ld tx,sx,ty,sy;
ld fx(ld time)
{
    return time*tx+min(time*sx,(ld)10);
}
ld fy(ld time)
{
    return time*ty+min(time*sy,(ld)10);
}
ld timex(ld tx,ld sx)
{
    ld l,r;
    l=(ld)0; r=(ld)101.0;
    for (int i=1;i<=500;i++)
    {
        ld mid=(l+r)/2.0;
        if (fx(mid)>=(ld)100.0) r=mid;
        else l=mid;
    } 
    return l;
}
ld timey(ld ty,ld sy)
{
    ld l,r;
    l=(ld)0; r=(ld)101.0;
    for (int i=1;i<=500;i++)
    {
        ld mid=(l+r)/2.0;
        if (fy(mid)>=(ld)100.0) r=mid;
        else l=mid;
    } 
    return l;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>tx>>sx>>ty>>sy;
        ld ttx=timex(tx,sx);
        ld tty=timey(ty,sy);
        // cout<<ttx<<" "<<tty<<"\n";
        if (abs(ttx-tty)<eps) cout<<"Draw\n";
        else 
        if (ttx<tty) cout<<"Megumin\n";
        else cout<<"Yunyun\n";
    }
}

