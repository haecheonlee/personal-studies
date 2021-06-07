/* reference: editorial */

#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	int a[N];
	
	bool flag = 1;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		if(a[i] < 0) flag = 0;
	}
	
	if(!flag) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		cout << 101 << '\n';
		for(int i = 0; i <= 100; i++) cout << i << ' ';
		cout << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
