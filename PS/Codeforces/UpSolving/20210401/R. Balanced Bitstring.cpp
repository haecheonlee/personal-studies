/* reference: ediotorial */

#include <iostream>

using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	string s; cin >> s;
	
	int zer = 0, one = 0;
	bool flag = 1;
	
	for(int i = 0; i < K; i++) {
		int tmp = -1;
		for(int j = i; j < N; j += K) {
			if(s[j] != '?') {
				if(tmp != -1 && s[j] - '0' != tmp) {
					flag = false;
					break;
				}
				tmp = s[j] - '0';
			}
		}
		if(tmp != -1) {
			(tmp == 0 ? zer : one)++;
		}
	}
	
	if(max(zer, one) > K / 2) flag = 0;
	cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
