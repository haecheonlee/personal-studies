#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int a1, a2; cin >> a1 >> a2;
	int k1, k2; cin >> k1 >> k2;
	int n; cin >> n;
	
	// always player1 smaller
	if(k1 > k2) swap(a1, a2), swap(k1, k2);
	int mn = min(n, (a1 * (k1 - 1)) + (a2 * (k2 - 1)));
	int s1 = min(a1, n / k1);
	int s2 = min(a2, (n - k1 * s1) / k2);
	
	cout << min((n - mn), a1 + a2) << ' ' << s1 + s2 << '\n';

	return 0;
}
