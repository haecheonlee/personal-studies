#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	
	int ans = 0;
	int one = 0, two = 0;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		
		x %= 3;
		if(x == 0) ans++;
		else if(x == 1) one++;
		else if(x == 2) two++;
	}
	
	int k = min(one, two);
	one -= k, two -= k;
	ans += k;
	
	ans += one / 3 + two / 3;
	cout << ans << '\n';
	
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
