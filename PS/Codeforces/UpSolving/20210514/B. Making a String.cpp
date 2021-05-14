#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 30;

int a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	ll ans = 0;
	for(int i = N - 1; i >= 0; i--) {
		if(i == N - 1) ans += a[i];
		else {
			if(a[i + 1] <= a[i]) a[i] = a[i + 1] - 1;
			if(a[i] >= 0) ans += a[i];
		}
	}
	cout << ans << '\n';
	
	return 0;
}
