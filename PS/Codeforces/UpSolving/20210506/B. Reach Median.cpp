#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N];

int main() {
	int N, K; cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);

	long long ans = 0;
	if(a[N / 2] == K) {
		cout << ans << '\n';
	} else if(a[N / 2] > K){
		for(int i = N / 2; i >= 0; i--) if(a[i] > K) ans += (a[i] - K);
		cout << ans << '\n';
	} else if(a[N / 2] < K) {
		for(int i = N / 2; i < N; i++) if(a[i] < K) ans += (K - a[i]);
		cout << ans << '\n';
	}

	return 0;
}
