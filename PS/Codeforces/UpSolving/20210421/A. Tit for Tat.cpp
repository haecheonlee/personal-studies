#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 10;

int a[MAX_N];

void solve() {
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	for(int i = 1; i < N && K; i++) { 
		if(a[i]) {
			int k = min(a[i], K);
			a[i] -= k, a[N] += k, K -= k;
		}
	}
	
	for(int i = 1; i <= N; i++) cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
