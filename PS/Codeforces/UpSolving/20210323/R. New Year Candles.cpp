#include <iostream>

using namespace std;

int main() {
	int N, M, K; cin >> N >> M;
	
	int ans = N;
	while(N >= M) {
		K = (N / M);
		ans += K;
		N = K + (N % M);
	}
	cout << ans << '\n';

	return 0;
}
