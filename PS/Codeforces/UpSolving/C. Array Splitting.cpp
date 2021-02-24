/* editorial */

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main() {
	fastio
	
	int N, K; cin >> N >> K;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];

	vector<int> p;
	for(int i = 1; i < N; i++) p.push_back(a[i - 1] - a[i]);
	sort(p.begin(), p.end());

	int ans = a[N - 1] - a[0];
	for(int i = 0; i < K - 1; i++) ans += p[i];
	cout << ans << '\n';
	
	return 0;
}
