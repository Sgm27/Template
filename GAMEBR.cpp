#include<bits/stdc++.h>
#define hoaf cout<<"\nhoaf13. I'm here ~";
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
 
const double pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;
 
 
int main(){
    freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int Teo=min(n,m);
	int Ti;
	int maxx=max(n,m);
	Ti = maxx-Ti-1;
	cout<<Ti<<" "<<Teo;
return 0;
}