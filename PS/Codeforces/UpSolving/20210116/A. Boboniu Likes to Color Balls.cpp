#include <iostream>

using namespace std;

int a[4];

void solve() {
	int odd = 0;
	for(int i = 0; i < 4; i++) {
		cin >> a[i];
		if(a[i] & 1) odd++;
	}
	
	int x = min(a[0], min(a[1], a[2]));
	int K = min(x, 1);
	for(int k = 0; k <= K; k++) {
		int o = 0;
		for(int i = 0; i < 4; i++) {
			if(i == 3) {
				if((a[i] + k) & 1) o++;	
			} else {
				if((a[i] - k) & 1) o++;
			}
		}
		odd = min(odd, o);
	}

	cout << (odd <= 1 ? "YES" : "NO") << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
