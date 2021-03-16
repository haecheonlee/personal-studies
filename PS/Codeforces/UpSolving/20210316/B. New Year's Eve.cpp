#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long N, K; cin >> N >> K;

	if(K == 1) cout << N << '\n';
	else if(K >= 2) {
		long long p = 1;
		while(N > 1) p++, N /= 2;

		cout << (1LL << p) - 1 << '\n';
	}

	return 0;
}
