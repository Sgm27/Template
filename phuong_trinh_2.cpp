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
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
 	ll n,d=1;
    cin>>n;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){
            ll k=0;
            while(n%i==0){
                n/=i;
                k++;
            }
            d*=2*k+1;
        }
    }
    if(n>1) d*=3;
    cout<<d<<endl;
 
return 0;
}
