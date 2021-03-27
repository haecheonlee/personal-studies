#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int main() {
	int N; cin >> N;
	
	ll now = 0, ans = 0;
	map<ll, bool> m; m[0] = 1;
	for(int i = 0; i < N; i++) {
		ll x ; cin >> x;
		now += x;
		if(m.find(now) != m.end()) {
			m.clear();
			m[0] = 1;
			now = x;
			ans++;
		}
		m[now] = 1;
	}
	cout << ans << '\n';
	
	return 0;
}
