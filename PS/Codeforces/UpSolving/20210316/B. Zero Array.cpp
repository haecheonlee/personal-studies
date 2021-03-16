/* reference: editorial */

#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	
	long long sum = 0, mx = 0;
	for(int i = 0; i < N; i++) {
		long long x; cin >> x;
		sum += x; mx = max(mx, x);
	}
	cout << (sum & 1 || (sum - mx) < mx ? "NO" : "YES") << '\n';

	return 0;
}
