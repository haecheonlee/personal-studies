#include <iostream>

using namespace std;
using ll=long long;

ll gcd(ll a, ll b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
	ll a,b;
	cin>>a>>b;
	
	ll r=gcd(a,b);
	cout<<((a/r)*(b/r))*r;
	
	return 0;
}
