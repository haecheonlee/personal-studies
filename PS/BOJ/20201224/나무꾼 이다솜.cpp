#include <iostream>

using namespace std;

int main() {
	int N, C, W;
	cin >> N >> C >> W;
	
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	long long ans = 0;
	for(int i = 1; i <= 10000; i++) {
		long long total = 0;
		
		for(int k = 0; k < N; k++) {
			long long benefit = 1LL * a[k] / i * W * i;
			long long cost = (a[k] == i ? 0 : ((a[k] - 1) / i) * C);

			if(benefit - cost > 0) total += benefit - cost;
		}
		
		ans = max(ans, total);
	}
	cout << ans << '\n';

	return 0;
}
