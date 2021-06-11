#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> a(N);
	
	long long sum = 0;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];	
	}
	
	if(sum % N) {
		cout << -1 << '\n';
	} else {
		sort(a.begin(), a.end());
		if(N == 1 || a[0] == a[N - 1]) {
			cout << 0 << '\n';
		} else {
			int avg = sum / N, need = 0;
			for(int i = 0; i < N; i++) if(a[i] < avg) need += (avg - a[i]);
			
			int ans = 0;
			for(int i = N - 1; i >= 0 && need > 0; i--) {
				int x = a[i] - avg;
				need -= x;
				ans++;
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
