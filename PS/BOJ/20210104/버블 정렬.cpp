/* reference: pyw0564 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> a(N), b(N);
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	sort(b.begin(), b.end());
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		int p = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		ans = max(ans, i - p);
	}
	cout << ans << '\n';
	
	return 0;
}
