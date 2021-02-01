/* reference: editorial */

#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 2e5 + 1;

int N, K;
int a[MAX_N];

bool chk(int mid, int now) {
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(!now) {
			now ^= 1;
			cnt++;
		} else {
			if(a[i] <= mid) {
				now ^= 1;
				cnt++;
			}
		}
	}
	
	return cnt >= K;
}

int main() {
	fastio
	
	cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int L = 1, R = 1e9;
	int ans = 0;
	while(L <= R) {
		int mid = (L + R) / 2;
		if(chk(mid, 0) || chk(mid, 1)) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	cout << ans << '\n';
	
	return 0;
}
