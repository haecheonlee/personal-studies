/* reference: Yungoon */

#include <iostream>

using namespace std;

void solve() {
	int N;
	cin >> N;
	
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	auto isHill = [&](int i) {
		if(i <= 1 || i >= N) return false;
		return a[i - 1] < a[i] && a[i] > a[i + 1];
	};
	
	auto isValley = [&](int i) {
		if(i <= 1 || i >= N) return false;
		return a[i - 1] > a[i] && a[i] < a[i + 1];
	};
	
	auto isPeek = [&](int i) {
		if(i <= 1 || i >= N) return false;
		return isHill(i) || isValley(i);
	};
	
	int cnt = 0;
	for(int i = 2; i <= N - 1; i++) cnt += isPeek(i);
	
	int m = 0;
	for(int i = 2; i <= N - 1; i++) {
		int original = a[i];
		int init = isPeek(i - 1) + isPeek(i) + isPeek(i + 1);
		int current = init;
		
		a[i] = a[i - 1];
		current = min(current, isPeek(i - 1) + isPeek(i) + isPeek(i + 1));
		
		a[i] = a[i + 1];
		current = min(current, isPeek(i - 1) + isPeek(i) + isPeek(i + 1));
		
		a[i] = original;
		m = max(m, init - current);
	}
	
	cout << cnt - m << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
