#include <iostream>
#include <set>

using namespace std;

void solve() {
	int N; cin >> N;
	set<int> ans;
	ans.insert(0);
	
	for(int i = 1; i * i <= N; i++) {
		ans.insert(N / (N / i));
		ans.insert(N / i);
	}
	
	cout << ans.size() << '\n';
	for(auto x : ans) cout << x << ' ';
	cout << '\n';
}


int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
