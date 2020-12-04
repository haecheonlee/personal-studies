/* reference: Cwolf9.0 */
 
#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	int T;
	cin >> T;
 
	while(T--) {
		int N;
		cin >> N;
 
		ll a[N + 1];
		ll sum = 0;
		for(int i = 1; i<= N; i++) {
			cin >> a[i];
			if(i > 1) sum += abs(a[i - 1] - a[i]);
		}
 
		ll ans = 1e18;
		for(int i = 1; i <= N; i++) {
			ll total = sum;
			
			if(i == 1) {
				total -= abs(a[1] - a[2]);
			} else if(i == N) {
				total -= abs(a[N] - a[N - 1]);
			} else {
				total -= abs(a[i - 1] - a[i]);
				total -= abs(a[i + 1] - a[i]);
				total += abs(a[i + 1] - a[i - 1]);
			}
			ans = min(ans, total);
		}
		cout << ans << '\n';
	}
 
	return 0;
}
