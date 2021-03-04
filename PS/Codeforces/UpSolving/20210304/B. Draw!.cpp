/* reference: JustasK */

#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	
	int ans = 1, a = 0, b = 0;
	for(int i = 0; i < N; i++) {
		int aa, bb; cin >> aa >> bb;
		if(aa == a && bb == b) continue;
		ans += max(0, min(bb, aa) - max(a, b) + 1);
		if(a == b) ans--;
		a = aa, b = bb;
	}
	cout << ans << '\n';

	return 0;
}
