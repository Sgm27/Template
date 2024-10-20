#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

bool isPrime(int n)
{
    if (n < 2)
        return false; // optional
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

long long power(long long a, long long d, long long n)
{
    if (d == 1)
        return a % n;
    else
    {
        long long k = power(a, d / 2, n);
        if (d % 2 == 0)
            return k * k % n;
        else
            return ((k * k) % n * a) % n;
    }
}
bool rabinMiller(long long n, int k)
{
    if (n <= 50)
        return isPrime(n);
    long long d = n - 1, s = 0;
    while (d % 2 == 0)
    {
        ++s;
        d /= 2;
    }
    for (int i = 1; i <= k; ++i)
    {
        long long a = rand() % (n - 2) + 2;
        long long x = power(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        for (int r = 1; r < s; ++r)
        {
            x = (long long)(x * x) % n;
            if (x == 1)
                return false;
            if (x == n - 1)
                break;
        }
        if (x != n - 1)
            return false;
    }
    return true;
}

int main()
{
    int test;
    long long n;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        scanf("%lld", &n);
        if (rabinMiller(n, 5))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
