#include<iostream>
using namespace std;
using ll = long long;
#define maxn 
int n,x[250],s=0,dong=0,mo=0;
bool check()
{
    int sum=0,dong=0,mo=0;
    bool ok=false;
    for (int i=1;i<=n;i++)
    {
        if (x[i]==-1) dong++;
        else mo++;
        if (mo>n/2 || dong>n/2) return false;
        sum+=x[i];
        if (sum<0) ok=true;
    }
    if (ok || sum!=0) return true;
    return false;
}
void in()
{
    for (int i=1;i<=n;i++) 
        if (x[i]==-1) cout<<")"; else cout<<"(";
    cout<<"\n";
}
void Try(int i)
{
    for (int j=1;j>=-1;j-=2)
        if (dong+(j==1)<=n/2+1 && mo+(j==-1)<=n/2+1)
        {
            if (j==-1) mo++;
            if (j==1) dong++;
            x[i]=j;
            s+=j;
            if (i==n)
            {
                if (check()) in();
            }
            else Try(i+1);
            s-=j;
        }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    n*=2;
    Try(1);
}