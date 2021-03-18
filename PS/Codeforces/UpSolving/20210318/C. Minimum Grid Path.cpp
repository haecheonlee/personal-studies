#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 1;

ll a[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	
	ll H = N, V = N;
	ll HS = a[0], VS = a[1];
	ll HM = a[0], VM = a[1];
	
	ll ans = (HM * H) + (VM * V);
	H--, V--;
	for(int i = 2; i < N; i++) {
		if(i & 1) VM = min(VM, a[i]);
		else HM = min(HM, a[i]);
		
		ans = min(ans, HS + VS + (HM * H) + (VM * V));
		
		if(i & 1) {
			if(V) VS += a[i], V--;
		} else {
			if(H) HS += a[i], H--;
		}
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
