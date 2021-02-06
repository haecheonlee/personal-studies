#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ll N, M, K; cin >> N >> M >> K;
	ll a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);
	
	ll k = M / (K + 1);
	ll m = M - k;
	
	cout << a[N] * m + a[N - 1] * k << '\n';
	
	return 0;
}
