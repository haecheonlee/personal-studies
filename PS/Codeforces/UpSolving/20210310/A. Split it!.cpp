#include <iostream>

using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	string s; cin >> s;
	
	if(K == 0) {
		cout << "YES" << '\n';
	} else {
		int same = 0;
		bool skipped = 0;
		for(int i = 0; i < N / 2; i++) {
			if(s[i] == s[N - i - 1]) same++;
			else {
				skipped = 1;
				break;
			}
		}
		same += (skipped || N & 1);
		cout << (same > K ? "YES" : "NO") << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
