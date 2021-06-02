#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map<ll,int> mp;

int main() {
	ll N; cin >> N;
	
	for(ll i = 2; i * i <= N; i++) {
		while(N % i == 0) {
			N /= i;
			mp[i]++;
		}
	}
	
	if(N > 1) mp[N]++;
	
	ll ans = 1;
	for(auto& x : mp) ans *= x.first;
	cout << ans << '\n';
	
	return 0;
}
