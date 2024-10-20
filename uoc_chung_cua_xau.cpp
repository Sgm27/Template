#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; ++i) {
      while (j && s[j] != s[i]) j = pi[j - 1];
      if (s[j] == s[i]) ++j;
      pi[i] = j;
    }
    return pi;
}

int compress(const string& s) {
  auto pi = kmp(s);
  int n = s.size();
  int k = n - pi.back();
  if (n % k) k = n;
  return k;
}

int main() {
    freopen("thu.inp","r",stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s1, s2;
  cin >> s1 >> s2;
  int k1 = compress(s1);
  int k2 = compress(s2);
  if (s1.substr(0, k1) != s2.substr(0, k2)) {
    cout <<0;
    return 0;
  }

  int g = -1 ,ans=0;
  int n1 = s1.size();
  int n2 = s2.size();
  for (int i = min(n1, n2); i; --i) {
    if ((n1 % i == 0) && (n2 % i == 0) && (i % k1 == 0) && (i % k2 == 0)) {
      ans++;
    }
  }
  cout<<ans;
  return 0;
}
