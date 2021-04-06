/* reference: editorial */

#include <iostream>

using namespace std;

const int MAX_N = 2e3 + 10;

int a[MAX_N];

int gcd(int x, int y) {
	return (y == 0 ? x : gcd(y, x % y));
}

int main() {
	int N; cin >> N;
	
	int cnt1 = 0;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] == 1) cnt1++;
	}
	
	if(cnt1) {
		cout << N - cnt1 << '\n';
	} else {
		int ans = -1;
		for(int i = 1; i <= N; i++) {
			int r = a[i], j;
			for(j = i; j <= N; j++) {
				r = gcd(r, a[j]);
				if(r == 1) break;
			}
			
			if(r == 1) {
				int K = j - i + 1;
				if(ans == -1 || ans > N + K - 2) ans = N + K - 2;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
