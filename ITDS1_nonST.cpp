#include<iostream>
#include<set>
using namespace std;
using ll = long long;
#define maxn 100005
int n,q,a[maxn];
set<pair<int,int>> se;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    se.insert({0,0});
    cin>>n>>q;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        se.insert(make_pair(a[i],i));
    }
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int i,val;
            cin>>i>>val;
            se.erase({a[i],i});
            se.insert({val,i});
            a[i]=val;
        }
        else
        {
            int l,r,k,check=0;
            cin>>l>>r>>k;
            auto it=se.lower_bound({k,l});
            while (it != se.end())
            {
                if (it->second>=l && it->second<=r)
                {
                    cout<<it->first<<"\n";
                    break;
                }
                it++;
            }
            if (it == se.end()) cout<<"-1\n";
        }
    }
}

