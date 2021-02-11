/* editorial */

#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 1;

int cnt[6];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x; 
		cnt[x]++;
	}
	
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		cnt[x]--;
	}

	int ans = 0;
	for(int i = 1; i <= 5; i++) {
		if(cnt[i] & 1) {
			cout << -1 << '\n';
			return 0;
		}
		ans += abs(cnt[i] / 2);
	}
	cout << ans / 2 << '\n';
	
	return 0;
}
