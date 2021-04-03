/* reference: send-off-a-friend */

#include <iostream>

using namespace std;

const int MAX_N = 3e5 + 10;

int c[MAX_N];

void solve() {
	int N; cin >> N;
	string s, ss; cin >> s >> ss;
	for(int i = 0; i < N; i++) 
		c[i] = s[i] - '0' + (i == 0 ? 0 : c[i - 1]);
	
	int rev = 0;
	for(int i = N - 1; i >= 0; i--) {
		if((s[i] ^ rev) != ss[i]) {
			if(c[i] * 2 != i + 1) {
				cout << "NO" << '\n';
				return;
			}
			rev ^= 1;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
