#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

int main() {
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int ans = a[1];
	if(K == 1) {
		for(int i = 1; i <= N; i++) ans = min(ans, a[i]);
	} else if(K == 2) {
		ans = max(a[1], a[N]);
	} else {
		for(int i = 1; i <= N; i++) ans = max(ans, a[i]);
	}
	cout << ans << '\n';
	
	return 0;
}
