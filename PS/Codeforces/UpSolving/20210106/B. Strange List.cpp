#include <iostream>
#include <queue>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		ll N, K;
		cin >> N >> K;
	
		pii a[N + 1];
		for(int i = 1; i <= N; i++) {
			cin >> a[i].fi;
			a[i].sc = a[i].fi;
		}
	
		ll ans = 0;
		while(1) {
			bool is_end = 0;
			for(int i = 1; i <= N; i++) {
				if(a[i].sc == 0) { is_end = 1; break; }
				else if(a[i].sc % K == 0) ans += a[i].fi, a[i].sc /= K;
				else if(a[i].sc % K != 0) ans += a[i].fi, a[i].sc = 0;
			}
			if(is_end) break;
		}
		cout << ans << '\n';
	}

	return 0;
}
