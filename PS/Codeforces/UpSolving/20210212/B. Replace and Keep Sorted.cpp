#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

int main() {
	int N, Q, K; cin >> N >> Q >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	while(Q--) {
		int l, r; cin >> l >> r;
		
		int z = r - l + 1;
		int o = a[l] - 1 + K - a[r];
		int t = K - z - o;
		
		cout << o + t * 2 << '\n';
	}
	
	return 0;
}
