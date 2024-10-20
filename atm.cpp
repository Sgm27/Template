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
int n;
int S;
int a[21];
int res = 99999;
 
void Try(int i , ll sum , int d){
	if (sum>S || d>res) return;	
	if(i==n){
		if (sum == S) res = min(res,d);
		return;
	}
	Try(i+1,sum,d);
	Try(i+1,sum+a[i],d+1);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	cin>>S;
	for(int i=0;i<n;i++) cin>>a[i];
	Try(0,0,0);
	if (res==99999) cout<<-1;
	else cout<<res;
 
return 0;
}
