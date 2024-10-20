#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base = 137;

long long GetRandom(long long Min,long long Max){
return Min + (long long)(rand()*(Max-Min+1.0)/(1.0+RAND_MAX));
}

signed main(){
freopen("thu.inp","w",stdout);
    // freopen("thu.ans","w",stdout);
    srand(time(NULL));
    long long Min = 1, Max = 1e18,m1=1,m2=1e1;
    
    long long k=50;
    long long q=GetRandom(5,10);
    // cout<<1<<"\n";
    q = 1;
    // cout<<q<<'\n';
    while (q--)
    {
        long long n=GetRandom(4, 6);
        int m = GetRandom(5,15);
        // cout<<n<<" "<<m<<"\n";
        cout<<n<<"\n";
        // cout<<n*1000<<" "<<val<<"\n";
        // continue;
        // n = 1;
        unordered_map<int,int> mark;
        // int len = GetRandom(n, 100);
        // len -= (len % 2);
        // FOR(i,1,len) 
        // {
        //     int t = GetRandom(0,0);
        //     if (t == 0) cout<<"?";
        //     else
        //     if (t == 1) cout<<")";
        //     else cout<<"(";
        // }
        // continue;
        FOR(i,1,n)
        {
            int x = GetRandom(0,1);
            int y = GetRandom(0,3);
            int z = GetRandom(0,3);
            // cout<<(x ? '+' : '-');
            if (x == 0)
                cout<<0<<" ";
            else    
                cout<<GetRandom(2,100)<<" ";
            continue;
            cout<<x<<" "<<y<<" "<<z<<"\n";
            continue;
            cout<<x<<" ";;
            continue;
            if (!mark[x])
            {
                cout<<x<<" ";
                mark[x] = 1;
            }
            else i--;
            // if (x == 1) cout<<"D";
            // else 
            // if (x == 2) cout<<"X";
            // else 
            //     cout<<"T";
        }
    // cout<<"\n";
        continue;
        FOR(i,1,m)
        {
            int x = GetRandom(1,3);
            int y = GetRandom(1e3,5e5);
            int z = GetRandom(100, 300);
            // cout<<(x ? '+' : '-');
            // cout<<x<<" "<<z<<" ";
            cout<<x<<" ";
        }
        cout<<"\n";
        // while (m--)
        // {
        //     int pos = GetRandom(1,n);
        //     int val = GetRandom(1,1e9);
        //     cout<<pos<<" "<<val<<"\n";
        // }
    }
    // cout<<"0";
    return 0;
}

