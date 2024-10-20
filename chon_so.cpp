#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
using ll = long long;
#define maxn 1000005
ll n;
vector<int> nto;
int prime[maxn+5];
void sang()
{
    int tmp=sqrt(n);
    for (int i=2;i<=sqrt(tmp);i++)
        if (!prime[i])
            for (int j=i*i;j<=tmp;j+=i) prime[j]=1;
    for (int i=2;i<=tmp;i++) 
        if (!prime[i]) nto.push_back(i);
} 
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    sang();
    ll res=1;
    for (int i=1;i<=sqrt(n);i++)
        if (n%i==0)
        {
            ll tmp=n/i;
            int check=1;
            for (int k : nto) 
            {
                if (k>sqrt(tmp)) break;
                if (tmp%(k*k)==0) 
                {
                    check=0;
                    break;
                }
            }
            if (check)
            {
                cout<<tmp;
                return 0;
            }
            tmp=i;
            check=1;
            for (int k : nto) 
            {
                if (k>sqrt(tmp)) break;
                if (tmp%(k*k)==0) 
                {
                    check=0;
                    break;
                }
            }
            if (check) res=max(res,tmp);
        }
    cout<<res;
}

