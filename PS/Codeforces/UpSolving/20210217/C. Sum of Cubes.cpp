#include <iostream>
#include <set>

using namespace std;

set<long long> p;

void solve() {
	long long x; cin >> x;

	for(auto it : p) {
		if(x < it) break;
		if(p.find(x - it) != p.end()) {
			cout << "YES" << '\n';
			return;
		}
	}
	
	cout << "NO" << '\n';
}

int main() {
	for(long long i = 1; i * i * i <= 1e12; i++) p.insert(i * i * i);

	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
