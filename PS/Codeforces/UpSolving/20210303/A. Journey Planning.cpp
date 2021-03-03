/* editorial */

#include <iostream>
#include <map>

using namespace std;

int main() {
	int N; cin >> N;
	
	map<int,long long> m;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		m[i - x] += x;
	}

	long long ans = 0;
	for(auto& it : m) ans = max(ans, it.second);
	cout << ans << '\n';
	
	return 0;
}
