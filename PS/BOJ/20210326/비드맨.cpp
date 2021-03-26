#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int N; cin >> N;
	
	ll mx = 0, sum = 0;
	for(int i = 0; i < N; i++) {
		ll x; cin >> x;
		mx = max(mx, x), sum += x;
	}
	
	cout << (mx * 2 > sum ? mx * 2 - sum : sum & 1) << '\n';
	
	return 0;
}
