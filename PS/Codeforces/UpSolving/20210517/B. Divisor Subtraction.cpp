/* reference: editorial */

#include <iostream>

using namespace std;

typedef long long ll;

ll get(ll N) {
	for(ll i = 2; i * i <= N; i++) 
		if(N % i == 0) return i;
	return N;
}

int main() {
	ll N; cin >> N;

	ll cnt = 0;
	if(N & 1) {
		N -= get(N);
		cnt++;
	}

	cout << cnt + N / 2 << '\n';

	return 0;
}
