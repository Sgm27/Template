#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 800005
struct mang{
    int v,p,delta;
};
mang a[maxn];
int n;
void input()
{
    cin>>n;
    n*=2;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].v>>a[i].p;
        a[i].delta=abs(a[i].v-a[i].p);
    }
} 
bool cmp(mang a,mang b)
{
    return a.delta>b.delta;
}
void process()
{
    sort(a+1,a+1+n,cmp);
    // for (int i=1;i<=n;i++) cout<<a[i].v<<" "<<a[i].p<<"\n";
    int V=n/2,P=n/2,idx=0,res=0;
    while (P || V)
    {
        bool check=false;
        idx++;
        if (a[idx].v==min(a[idx].v,a[idx].p) && V)
        {
            res+=a[idx].v;
            V--;
            check=true;
        }
        else 
        if (a[idx].p==min(a[idx].v,a[idx].p) && P)
        {
            res+=a[idx].p;
            P--;
            check=true;
        }
        if (!check) 
            if (V) 
            {
                res+=a[idx].v;
                V--;
            }
            else 
            if (P)
            {
                res+=a[idx].p;
                P--;
            }
    }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

