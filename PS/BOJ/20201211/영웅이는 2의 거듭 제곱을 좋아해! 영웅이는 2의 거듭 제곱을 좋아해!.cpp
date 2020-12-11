/* reference: sdy1437 */

#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
	fastio
	
	int N;
	cin >> N;
	
	int x = 0, ans = 0;
	int a[N];
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		x ^= a[i];	
	}
	
	ans = x;
	for(int i = 0; i < N; i++) ans = max(ans, x ^ a[i]);
	
	cout << ans << ans << '\n';
	
	return 0;
}
