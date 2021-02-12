#include <iostream>

using namespace std;

void solve() {
	int a, b; cin >> a >> b;
	
	if(b >= a) {
		cout << (b == a ? 2 : 1) << '\n';
		return;
	}
	
	int ans = 1e9;
	for(int i = b; i <= a; i++) {
		int cnt = (i - b);
		if(i == 1) {
			continue;
		} else {
			int A = a;
			while(A) {
				A /= i;
				cnt++;
			}
		}
		
		ans = min(ans, cnt);
		if(cnt > ans) break;
	}
	
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
