/* reference: https://giiro.tistory.com/entry/%EB%B0%B1%EC%A4%80-2381-%EC%B5%9C%EB%8C%80%EA%B1%B0%EB%A6%AC */

#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

int main() {
	fastio
	
	int N;
	cin >> N;
	
	pii a[N];
	for(int i = 0; i < N; i++) cin >> a[i].fi >> a[i].sc;
	
	int r1, r2;
	
	int mx = -1e9, mn = 1e9;
	for(int i = 0; i < N; i++) {
		mx = max(mx, a[i].fi + a[i].sc);
		mn = min(mn, a[i].fi + a[i].sc);
	}

	r1 = mx - mn;

	mx = -1e9, mn = 1e9;
	for(int i = 0; i < N; i++) {
		mx = max(mx, a[i].fi - a[i].sc);
		mn = min(mn, a[i].fi - a[i].sc);
	}
	
	r2 = mx - mn;
	
	cout << max(r1, r2) << '\n';

	return 0;
}
