#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int ca,cb,ma,mb;
void process()
{
    if ((!ca && !cb) || (!ma && !mb))
    {
        cout<<"0\n";
        return;
    }
    if ((!ca && cb) || (!ma && mb))
    {
        cout<<min(cb,mb)<<"\n";
        return;
    }
    if ((ca && !cb) || (ma && !mb))
    {
        cout<<min(ca,ma)<<"\n";
        return;
    }
    if (ca>cb)
    {
        swap(ca,cb);
        swap(ma,mb);
    }
    // can tim so luong B lon nhat duoc chen vao
    ll MaxB=min(1ll*(ca+1)*mb,1ll*cb);
    // chen them A vao MaxB
    cout<<ca+MaxB<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>ca>>cb>>ma>>mb;
        process();
    }
}

