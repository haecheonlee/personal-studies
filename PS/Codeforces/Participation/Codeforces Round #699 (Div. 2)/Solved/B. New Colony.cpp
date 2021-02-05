#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve() {
	int N, K; cin >> N >> K;
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];

	int k = 0, mx = 0;
	for(int i = N; i >= 1; i--) {		
		mx = max(mx, a[i]);
		k += (mx - a[i]);
	}
	
	if(k < K) {
		cout << -1 << '\n';
	} else {
		int kk = 0;
		while(1) {
			for(int i = 1; i <= N - 1; i++) {
				if(a[i] < a[i + 1]) {
					a[i]++, kk++;
					if(kk == K) {
						cout << i << '\n';
						return;
					}
					i = 0;
				}				
			}
		}
		
	}
}

int main() {
	fastio
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
