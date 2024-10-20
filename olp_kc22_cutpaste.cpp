#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = float;
const ld eps=1e-3;
#define maxn 
int q;
ld tmp[4],dist[4];
ld dis(ld x1,ld y1,ld x2,ld y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
bool cmp(ld a,ld b)
{
    return (abs(a-b)<eps);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ld xa,ya,xb,yb,xc,yc,xd,yd;
    cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
    dist[0]=dis(xa,ya,xb,yb);
    dist[1]=dis(xb,yb,xc,yc);
    dist[2]=dis(xc,yc,xd,yd);
    dist[3]=dis(xd,yd,xa,ya);
    sort(dist+1,dist+4);
    cin>>q;
    int ans=0;
    while (q--)
    {
        bool flag=true;
        cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
        tmp[0]=dis(xa,ya,xb,yb);
        tmp[1]=dis(xb,yb,xc,yc);
        tmp[2]=dis(xc,yc,xd,yd);
        tmp[3]=dis(xd,yd,xa,ya);
        sort(tmp+1,tmp+4);
        for (int i=0;i<4;i++)
            if (tmp[i]!=dist[i]) 
            {
                flag=false;
                break;
            }
        if (flag) ans++;
    }
    cout<<ans;
}

