#include <iostream>

using namespace std;

const int MAX_N = 5e2 + 10;

int a[MAX_N];

int main() {
	int N, K; cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> a[i];

	int ans = 0;
	for(int i = 1; i < N; i++) {
		int sum = a[i] + a[i - 1];
		if(sum < K) {
			a[i] += (K - sum);
			ans += (K - sum);
		}
	}
	
	cout << ans << '\n';
	for(int i = 0; i < N; i++) cout << a[i] << ' ';

	return 0;
}
