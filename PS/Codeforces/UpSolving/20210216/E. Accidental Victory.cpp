#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

void solve() {
	int N; cin >> N;
	pii a[N + 2];
	
	for(int i = 1; i <= N; i++) {
		cin >> a[i].fi;
		a[i].sc = i;
	}
	sort(a + 1, a + 1 + N);
	
	a[N + 1].fi = 0;
	long long p[N + 1] {0};
	for(int i = 1; i <= N; i++) p[i] = a[i].fi + p[i - 1];
	
	vector<int> ans;
	for(int i = N; i >= 1; i--) {
		if(p[i] >= a[i + 1].fi) {
			ans.push_back(a[i].sc);
		} else {
			break;
		}
	}
	sort(ans.begin(), ans.end());
	
	cout << ans.size() << '\n';
	for(auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
