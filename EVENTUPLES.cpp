#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,q,a[maxn];
struct node{
    int le,chan;
};
node t[maxn];
ll calc(pair<int,int> it)
{
    int chan=it.second,le=it.first;
    return 1ll*(le-1)*le/2*chan+1ll*(chan-2)*(chan-1)*chan/6;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        t[i]=t[i-1];
        if (a[i]%2) t[i].le++;
        else t[i].chan++;
    }
    while (q--)
    {
        int l,r;
        cin>>l>>r; 
        pair<int,int> cnt;
        cnt.first=t[r].le-t[l-1].le;
        cnt.second=t[r].chan-t[l-1].chan;
        cout<<calc(cnt)<<"\n";
    }
}

