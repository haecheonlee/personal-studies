/* editorial */

#include <iostream>
#include <vector>

#define sz(x) (int)x.size()

using namespace std;

string s;

int calc(int a, int b) {
	int cnt = 0;
	for(auto& x : s) {
		if(x - '0' == a) {
			cnt++;
			swap(a, b);
		}
	}
	
	if(a != b && cnt % 2 == 1) cnt--;
	return cnt;
}

void solve() {
	cin >> s;
	
	int ans = 0;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			ans = max(ans, calc(i, j));
	
	cout << sz(s) - ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
