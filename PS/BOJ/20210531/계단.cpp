#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N], d[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];

	int ans = 1;
	for(int i = 1; i <= N; i++) {
		if(a[i] > a[i - 1]) d[i] = d[i - 1] + 1;
		else d[i] = min(d[i - 1] + 1, a[i]);
		ans = max(ans, d[i]);
	}
	cout << ans << '\n';

	return 0;
}
