#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int xend,yend,cs=1e3,nmax=2005,ts[2005][2005];
int dx[8]={2,2,1,1,-1,-1,-2,-2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};
bool d[2005][2005],cx[2005][2005];
void process()
{
    int res=0;
    queue<int> qx;
    queue<int> qy;
    qx.push(cs); 
    qy.push(cs);
    ts[cs][cs]=0;
    while (!qx.empty())
    {
        int x=qx.front();
        int y=qy.front();
        qx.pop();
        qy.pop();
        for (int k=0;k<=7;k++)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if (xx>0 && xx<=nmax && yy>0 && xx<=nmax && d[xx][yy] && cx[xx][yy])
            {
                qx.push(xx);
                qy.push(yy);
                cx[xx][yy]=false;
                ts[xx][yy]=ts[x][y]+1;
                if (xx==xend && yy==yend) 
                {
                    cout<<ts[xend][yend]<<"\n";
                    return;
                }
            }
        }
    }
    cout<<"-1\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        memset(d,true,sizeof(d));
        memset(cx,true,sizeof(cx));
        int n;
        cin>>xend>>yend;
        xend+=cs;
        yend+=cs;
        cin>>n;
        while (n--)
        {
            int x,y;
            cin>>x>>y;
            x+=cs;
            y+=cs;
            d[x][y]=false;
        }
        process();
    }
}

