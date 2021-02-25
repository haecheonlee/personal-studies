/* editorial */

#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 2e5 + 1;

int a[MAX_N], b[MAX_N], p[MAX_N];
map<int, int> offset;

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	
	for(int i = 1; i <= N; i++) cin >> b[i];
	for(int i = 1; i <= N; i++) {
		int now = p[b[i]] - i;
		if(now < 0) now += N;
		offset[now]++;
	}
	
	int ans = 0;
	for(auto& it : offset) ans = max(ans, it.second);
	cout << ans << '\n';

	return 0;
}
