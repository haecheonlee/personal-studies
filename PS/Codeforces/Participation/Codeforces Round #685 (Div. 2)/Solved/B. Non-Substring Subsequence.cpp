#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N, Q;
		cin >> N >> Q;

		string s;
		cin >> s;	

		while(Q--) {
			int L, R;
			cin >> L >> R;

			string ss = s.substr(L - 1, R - L + 1);

			bool ans = false;
			for(int k = 0; k < (int)ss.size() - 1; k++) {
				int now = 0;
				for(int i = 0; i < N; i++) {
					if(s[i] == ss[now]) {
						if(k == now) i++;
						now++;
					}

					if(now == (int)ss.size()) {
						ans = true;
						break;
					}
				}

				if(ans) break;
			}

			cout << (ans ? "YES" : "NO") << '\n';
		}
	}

	return 0;
}
