#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int a[3];
	for(int i = 0; i < 3; i++) cin >> a[i];
	sort(a, a + 3);
	
	if(a[2] <= a[0] + a[1]) cout << (a[0] + a[1] + a[2]) / 2 << '\n';
	else cout << a[0] + a[1] << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
