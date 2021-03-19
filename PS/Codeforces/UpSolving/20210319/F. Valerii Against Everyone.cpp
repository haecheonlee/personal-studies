#include <iostream>
#include <set>

using namespace std;

void solve() {
	int N; cin >> N;
	
	set<int> s;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	
	cout << (s.size() == N ? "NO" : "YES") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
