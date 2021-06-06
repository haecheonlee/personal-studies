/* editorial */

#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		if(i & 1) a[i] = abs(a[i]);
		else a[i] = -abs(a[i]);
	}
	
	for(int i = 0; i < N; i++) cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
