#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

void solve() {
	int N; cin >> N;

	int a[N + 1];
	bool check[N + 1];

	int k = 1e9 + 1;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		check[i] = 0;
		k = min(k, a[i]);
	}

	vector<int> p;
	for(int i = 1; i <= N; i++) {
		if(a[i] % k == 0) {
			check[i] = 1;
			p.push_back(a[i]);
		}
	}
	sort(p.begin(), p.end());

	int L = 0;
	int ans[N + 1];
	for(int i = 1; i <= N; i++) {
		if(check[i]) ans[i] = p[L++];
		else ans[i] = a[i];
	}

	for(int i = 1; i <= N - 1; i++) {
		if(ans[i] > ans[i + 1]) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	fastio
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
