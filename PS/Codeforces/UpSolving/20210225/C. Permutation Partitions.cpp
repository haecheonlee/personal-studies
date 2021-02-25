#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 1;
const int MOD = 998244353;

int a[MAX_N];
vector<int> p;

int main() {
	int N, K; cin >> N >> K;
	
	long long sum = 0;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] >= N - K + 1) {
			sum += a[i];
			p.push_back(i);
		}
	}
	
	long long ans = 1;
	for(int i = 0; i < K - 1; i++) {
		ans *= (1LL * p[i + 1] - p[i]) % MOD;
		ans %= MOD;
	}
	cout << sum << ' ' << ans << '\n';

	return 0;
}
