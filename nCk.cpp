#include <iostream>

using namespace std;

const int MOD = 137777;
const int MAX = 1000000;

int factorial[MAX + 1];
int inverseFactorial[MAX + 1];

int power(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (1LL * result * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}

void initializeFactorials() {
    factorial[0] = inverseFactorial[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
        inverseFactorial[i] = power(factorial[i], MOD - 2);
    }
}

int nCk(int n, int k) {
    if (k > n) {
        return 0;
    }
    int numerator = factorial[n];
    int denominator = (1LL * inverseFactorial[k] * inverseFactorial[n - k]) % MOD;
    return (1LL * numerator * denominator) % MOD;
}

int main() {
    freopen("thu.inp","r",stdin);
    initializeFactorials();
    int n, k;
    // cin >> n;
    // cin >> k;
    n=1200,k=600;

    int result = nCk(n, k);
    cout<<result;

    return 0;
}
