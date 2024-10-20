#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int a[maxn],n;
void process()
{
    vector<int> res;
    res.clear();
    a[n+1]=-1;
    int cnt=1,pre_cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==a[i+1]) cnt++;
        else 
        {
            if (cnt==1) 
            {
                cout<<"-1\n";
                return;
            }
            else 
            {
                res.push_back(cnt+pre_cnt);
                for (int i=1;i<cnt;i++) res.push_back(i+pre_cnt);
                pre_cnt+=cnt;
                cnt=1;
            }
        }
    }
    for (int x : res) cout<<x<<" ";
    cout<<endl;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        process();	
    }
}

