#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 10;

ll arr[MAX_N];

int main() {
	ll N, a, b, k; cin >> N >> a >> b >> k;
	for(int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	int ans = 0;
	vector<ll> skip;
	for(int i = 0; i < N; i++) {
		if(arr[i] <= a) {
			ans++;
		} else {
			ll rest = (arr[i] - a) % (b + a);
			if(rest > b) {
				ans++;
			} else {
				ll need = (rest + (a - 1)) / a;
				skip.push_back(need);	
			}
		}
	}
	sort(skip.begin(), skip.end());
	for(auto& x : skip) {
		if(x <= k) {
			k -= x;
			ans++;
		} else {
			break;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
