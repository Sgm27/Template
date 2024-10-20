#include<bits/stdc++.h>
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define el "\n"
#define memset(a, x) memset(a, (x), sizeof(a));
#define sz(x) x.size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define mp make_pair
#define pll pair<long long, long long>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using str = string;
const ll INF = 1e9;
const ll MAXN = (1 << 20) + 55;
const ll MOD = 1e9 + 7;
#define yes cout << "yes" << el;
#define no cout << "no" << el;
#define umap unordered_map
#define BitON(i, mask) ((mask >> i) & 1)
#define cont continue
ll gcd(ll x, ll y){
    return !y?x:gcd(y,x%y);
}
ll pow_mod(ll a, ll b, ll m) { ll res = 1; while(b){ res = res * (b & 1 ? a : 1) % m; a = a * a % m; b >>= 1; } return res; }
ll POW(ll a, ll b) { ll res = 1; while(b){ res = res * (b & 1 ? a : 1); a = a * a; b >>= 1; } return res; }
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s) {
    setIn(s+".inp"); setOut(s+".out");
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MAX_DIGIT = 32;
const ll BASE = 1e9;
struct Bignum {
    int numDigit, digits[MAX_DIGIT];
    Bignum(long long x = 0) {
        memset(digits, 0);
        numDigit = 0;
        if (x == 0) {
            numDigit = 1;
            return;
        }
        while (x > 0) {
            digits[numDigit++] = x % BASE;
            x /= BASE;
        }
    }
    void operator += (const Bignum &x) {
        int tmp = max(numDigit, x.numDigit), carry = 0; 
        numDigit = tmp;
        for (int i = 0; i < tmp; i++) {
            digits[i] += x.digits[i] + carry;
            if (digits[i] >= BASE) {
                digits[i] -= BASE;
                carry = 1;
            } else carry = 0;
        }
        if (carry > 0) digits[numDigit++] = carry;
    }
    Bignum operator + (const Bignum &x) const {
        Bignum res = *this; res += x; return res;
    }
    void operator -= (const Bignum &x) {
        int carry = 0;
        for (int i = 0; i < numDigit; i++) {
            digits[i] -= x.digits[i] + carry;
            if (digits[i] < 0) {
                digits[i] += BASE;
                carry = 1;
            } else carry = 0;
        }
        while (numDigit > 1 && digits[numDigit - 1] == 0) numDigit--;
    }
    Bignum operator - (const Bignum &x) const {
        Bignum res = *this; res -= x; return res;
    }
    Bignum operator * (const Bignum &x) const {
        Bignum res(0);
        for (int i = 0; i < numDigit; i++) for (int j = 0; j < x.numDigit; j++) {
            long long tmp = 1LL * digits[i] * x.digits[j];
            int pos = i + j;
            while (tmp > 0) {
                tmp += res.digits[pos];
                res.digits[pos] = tmp % BASE;
                tmp /= BASE;
                pos++;
            }
        }
        res.numDigit = 1;
        for (int i = 0; i < MAX_DIGIT; i++) if (res.digits[i] > 0) 
            res.numDigit = i + 1;
        return res;
    }
    long long operator % (long long x) const {
        long long res = 0;
        for (int i = numDigit - 1; i >= 0; i--) res = (BASE * res + digits[i]) % x;
        return res;
    }
    Bignum operator / (long long x) const {
        Bignum res(0);
        long long rem = 0;
        for (int i = numDigit - 1; i >= 0; i--) {
            res.digits[i] = (BASE * rem + digits[i]) / x;
            rem = (BASE * rem + digits[i]) % x;
        }

        res.numDigit = numDigit;
        while (res.numDigit > 1 && res.digits[res.numDigit - 1] == 0) res.numDigit--;
        return res;
    }
    int compare(const Bignum &x) const {
        if (numDigit != x.numDigit) return numDigit > x.numDigit ? 1 : -1;
        for (int i = numDigit - 1; i >= 0; i--) if (digits[i] != x.digits[i])
            return digits[i] > x.digits[i] ? 1 : -1;
        return 0;
    }

    string toString(void) const {
        string res;
        for (int i = 0; i < numDigit; i++) {
            int tmp = digits[i];
            for (int j = 0; j < 9; j++) {
                res.push_back(tmp % 10 + '0');
                tmp /= 10;
            }
        }
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
ll a[200005], n, res = 0;
Bignum sum(0), sub(0), P, ans(0);
main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        sum += a[i];
        sub += a[i] * a[i];
    }
    P = sum * sum - sub;
    P = P / 2;
    Bignum tmp(0);
    for (int i = 0; i < n; i++){
        tmp = P;
        tmp = tmp * a[i];
        ans += tmp;
        tmp = sum;
        tmp -= a[i];
        tmp = tmp * a[i] * a[i];
        ans -= tmp;
    }
    ans = ans / 3;
    ans = ans % MOD;
    cout << ans.toString() << el;
}
