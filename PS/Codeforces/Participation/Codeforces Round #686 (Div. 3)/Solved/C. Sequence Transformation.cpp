#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		vector<int> a[N + 1];
		for(int i = 0; i < N; i++) {
			int x;
			cin >> x;

			a[x].push_back(i);
		}

		int ans = (N == 1 ? 0 : N);
		for(int i = 1; i <= N; i++) {
			if(a[i].empty()) continue;
			if(sz(a[i]) == 1) {
				if(a[i][0] == 0 || a[i][0] == N - 1) ans = min(ans, 1);
				else ans = min(ans, 2);
			} else {
				int L = sz(a[i]);
				int total = (a[i][0] == 0 ? 0 : 1);
				for(int j = 1; j < L; j++) {
					if(a[i][j] - a[i][j - 1] != 1) total++;
				}
				if(a[i][L - 1] != N - 1) total++;
				ans = min(ans, total);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
