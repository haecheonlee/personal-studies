#include <iostream>

using namespace std;

int main() {
	int N, K; cin >> N >> K;
	
	if(N == K || K == 0) {
		cout << 0 << ' ' << 0 << '\n';
	} else {
		int l = 1, r = min(N - K, K * 2);
		cout << l << ' ' << r << '\n';
	}
	
	return 0;
}
