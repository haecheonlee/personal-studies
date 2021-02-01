#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	
	int K = N, odd = 0, even = 0;;
	for(int i = 2; i * i <= K; i++) {
		if(K % i == 0) {
			if(i & 1) odd++;
			else even++;
			
			K /= i;
			i = 1;
		}
	}

	if(K != 1) {
		if(K & 1) odd++;
		else even++;
	}

	if(N == 1) cout << "FastestFinger" << '\n';
	else if(N == 2) cout << "Ashishgup" << '\n';
	else if(!even) cout << "Ashishgup" << '\n';
	else if(!odd) cout << "FastestFinger" << '\n';
	else cout << ((even == 1 && odd == 1) ? "FastestFinger" : "Ashishgup") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
