/* reference: JJaewon */

#include <iostream>

using namespace std;

typedef long long ll;

ll p[40];

int main() {
	
	p[0] = 1;
	for(int i = 1; i < 40; i++) p[i] = p[i - 1] * 3;
	int Q; cin >> Q;
	
	while(Q--) {
		ll N; cin >> N;
		ll ans = 0, i;
		for(i = 0; ans <= N; i++) ans += p[i];
		for(; i >= 0; i--) if(ans - p[i] >= N) ans -= p[i];
		cout << ans << '\n';
	}
	
	return 0;
}
