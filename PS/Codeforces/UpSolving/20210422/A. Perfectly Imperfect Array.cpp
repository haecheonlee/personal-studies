#include <iostream>
#include <cmath>

using namespace std;

void solve() {
	int N; cin >> N;
	
	bool flag = 1;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		int s = sqrt(x);
		
		if(s * s != x) flag = 0;
	}
	
	cout << (flag ? "NO" : "YES") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
