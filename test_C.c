#include <stdio.h>

// Hàm nhân hai s? nguyên l?n a và b
long long multiply(long long a, long long b) {
    long long result = 0;
    int sign = 1;
    if (a < 0) {
        sign = -sign;
        a = -a;
    }
    if (b < 0) {
        sign = -sign;
        b = -b;
    }
    while (b != 0) {
        if (b & 1) {
            result += a;
        }
        a <<= 1;
        b >>= 1;
    }
    return sign * result;
}

int main() {
    long long a = 1234567890123456789;
    long long b = 9876543210987654321;
    long long c = multiply(a, b);
    printf("%lld x %lld = %lld\n", a, b, c);
    return 0;
}
