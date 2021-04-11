#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 10;

int a[MAX_N];

void solve() {
	int N, K; cin >> N >> K;
	
	if(N <= 2) {
		if(K == 0) for(int i = 1; i <= N; i++) cout << i << ' ';
		else cout << -1;
		cout << '\n';
	} else {
		for(int i = 1; i <= N; i++) a[i] = i;
			
		for(int i = 2; i <= N - 1 && K; i += 2) {
			swap(a[i], a[i + 1]);
			if(K > 0) K--;
		}
		
		if(K == 0) for(int i = 1; i <= N; i++) cout << a[i] << ' ';
		else cout << -1;
		cout << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
