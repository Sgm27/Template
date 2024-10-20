#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define BIT(i,n) (((n) >> (i))&1)
#define MASK(i) ((1LL) << (i))
#define ins insert
#define ff first
#define ss second

int t,n,q,k;

const int N = 60+5;
const ll MOD = 1e15+7;
const ll MIN = -1e18;


ll m[4][4] = {{1,0,0,0},
                {1,1,1,0},
                {1,1,0,1},
                {1,1,0,0}};
ll f[4][4];

long long nhan(long long a, long long b) {
    long long c = 0;
    while (b) {
        if (b & 1) {
            c += a;
            if (c >= MOD) c -= MOD;
        }
        a += a; if (a >= MOD) a -= MOD;
        b /= 2;
    }
    return c;
}

void Mul(ll f1[4][4], ll f2[4][4]){
    ll tmp[4][4];
    fu(i,0,3)
        fu(j,0,3){
            tmp[i][j] = 0;
            fu(k,0,3)
                tmp[i][j]+=nhan(f1[i][k], f2[k][j])%MOD,
                tmp[i][j]%=MOD;
        }
    
    fu(i,0,3)
        fu(j,0,3)
            f[i][j] = tmp[i][j];
}

void Pow(int k){
    if(k <= 1) return;
    Pow(k/2);
    Mul(f,f);
    if(k&1) Mul(f,m);
}


void solve(){
    fu(i,0,3)
        fu(j,0,3) f[i][j] = m[i][j];
    Pow(n-3);
    cout << ((ll)6*f[0][0]%MOD + (ll)3*f[1][0]%MOD + (ll)2*f[2][0]%MOD + f[3][0]%MOD)%MOD << nl;
}

void nhap(){
    cin >> t;
    while(t--){
        cin >> n;
        if(n<=3) cout << n*(n+1)/2 << nl;
        else
        solve();
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
nhap();
}
