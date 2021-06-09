#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll N; cin >> N;
	
	ll ans = 0;
	if(N < 10) {
		ans = N;	
	} else {
		ans = 9;
		ll now = 10, cnt = 2;
		while(now <= N) {
			ans += (min(now * 10 - 1, N) - now + 1) * cnt;
			now *= 10, cnt++;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
