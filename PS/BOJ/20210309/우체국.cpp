#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
	int N; cin >> N;
	vector<pll> a(N);
	for(int i = 0; i < N; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	
	for(int i = 1; i < N; i++) a[i].second += a[i - 1].second;
	ll K = (a.back().second + 1) / 2;
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(K <= a[i].second) {
			ans = a[i].first;
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}
