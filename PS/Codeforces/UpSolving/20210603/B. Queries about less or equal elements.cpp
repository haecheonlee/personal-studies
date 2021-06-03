#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, M; cin >> N >> M;
	
	vector<int> a(N);
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	for(int i = 0; i < M; i++) {
		int x; cin >> x;
		int ans = upper_bound(a.begin(), a.end(), x) - a.begin();
		cout << ans << ' '; 
	}

	return 0;
}
