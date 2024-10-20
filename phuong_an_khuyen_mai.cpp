#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int luu[10];
vector<int> l1,l2,l3;
bool checkl2(int n)
{
    int x=n,sum=0;
    while (x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum%10==0;
}
bool checkl1(int n)
{
    int x=n;
    while (x)
    {
        if (x%10==0) return false;
        x/=10;
    }
    return true;
}
void xl()
{
    if (!luu[1]) return;
    int tmp=0;
    for (int i=1;i<=3;i++) tmp=tmp*10+luu[i];
    for (int i=3;i>=1;i--) tmp=tmp*10+luu[i];
    l3.push_back(tmp);
}
void Try(int i)
{
    for (int j=0;j<=9;j++)
    {
        luu[i]=j;
        if (i==3) xl();
        else Try(i+1); 
    }
}
void init()
{
    Try(1);
    for (int x : l3)
        if (checkl2(x)) l2.push_back(x);
    for (int x : l2)
        if (checkl1(x)) l1.push_back(x);
}
void process(int n,int m,int k)
{
    int sl1=l1.size(),sl2=l2.size(),sl3=l3.size();
    if (n>sl1)
    {
        cout<<"NO\n";
        return;
    }
    sl2-=n;
    if (m>sl2)
    {
        cout<<"NO\n";
        return;
    }
    sl3=sl3-n-m;
    if (k>sl3)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n,m,k;	
        cin>>n>>m>>k;
        process(n,m,k);
    }
}

