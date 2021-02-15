#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	int ans = 1, L = 0, R = 1;
	while(L <= R) {
		if(R < N) {
			if(a[R] - a[L] <= 5) R++;
			else L++;
		} else {
			L++;
		}

		ans = max(ans, R - L);
	}
	cout << ans << '\n';
	
	return 0;
}
