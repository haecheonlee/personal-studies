#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll N; cin >> N;
	
	ll L = 1, R = N, ans = R;
	while(L <= R) {
		ll M = (L + R) / 2;
		int flag = 0;
		ll now = N, eaten = 0;

		while(now > 0) {
			if(flag & 1) {
				now -= (now / 10);
			} else {
				eaten += min(M, now), now -= min(M, now);
			}
			
			flag ^= 1;
		}

		if(eaten * 2 >= N) R = M - 1, ans = M;
		else L = M + 1;
	}
	cout << ans << '\n';
	
	return 0;
}
