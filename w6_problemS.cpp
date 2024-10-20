#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
string s;
int n=0,res[85];
bool hang[15][15],cot[15][15],vuong[15][15],flag=false;
struct mang{
    int x,y,vv;
};
mang a[85];
int v(int i,int j)
{
    if (j<=3)
    {
        if (i<=3) return 1;
        if (i<=6) return 4;
        if (i<=9) return 7;
    }
    if (j<=6)
    {
        if (i<=3) return 2;
        if (i<=6) return 5;
        if (i<=9) return 8;
    }
    if (j<=9)
    {
        if (i<=3) return 3;
        if (i<=6) return 6;
        if (i<=9) return 9;
    }
}
void in()
{
    flag=true;
    int idx=0,i=1;
    while (idx<81)
    {
        if (s[idx]=='.') cout<<res[i++];
        else cout<<s[idx];
        idx++;
    }
    cout<<"\n";
}
void Try(int i)
{
    if (flag) return;
    for (int j=1;j<=9;j++)
        if (hang[a[i].x][j] && cot[a[i].y][j] && vuong[a[i].vv][j])
        {
            res[i]=j;
            hang[a[i].x][j]=false;
            cot[a[i].y][j]=false;
            vuong[a[i].vv][j]=false;
            if (i==n)
                in();
            else Try(i+1);
            hang[a[i].x][j]=true;
            cot[a[i].y][j]=true;
            vuong[a[i].vv][j]=true;
        }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(hang,true,sizeof(hang));
    memset(cot,true,sizeof(cot));
    memset(vuong,true,sizeof(vuong));
    cin>>s;
    int cs=0;
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
        {
            char x=s[cs++];
            if (x=='.') a[++n]={i,j,v(i,j)};
            else{
                int tmp=x-'0';
                if (!hang[i][tmp] || !cot[j][tmp] || !vuong[v(i,j)][tmp]) return 0;
                hang[i][tmp]=false;
                cot[j][tmp]=false;
                vuong[v(i,j)][tmp]=false;
            }
        }
    Try(1);
}

