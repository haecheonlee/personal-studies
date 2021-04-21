#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX_N = 1e2 + 10;

ll a[MAX_N];
int cnt[MAX_N];

void solve() {
	ll N, K; cin >> N >> K;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	bool flag = 1;
	for(int i = 1; i <= N; i++) {
		if(a[i] == 1) {
			if(cnt[0]) flag = 0;
			else cnt[0]++;
		} else if(a[i] > 0) {
			while(a[i] >= K) {
				ll x = 1, used = 0;
				for(int j = 0; j <= 100 && x < a[i] && x * K <= a[i]; j++) x *= K, used++;
				a[i] -= x;
				cnt[used]++;
			}

			if(a[i] == 1) cnt[0]++;
			else if(a[i] > 0) flag = 0;
		}
	}
	
	for(int i = 0; i <= 100; i++) if(cnt[i] >= 2) flag = 0;
	cout << (flag ? "YES" : "NO") << '\n';	
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
