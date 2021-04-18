/* reference: green55 */

#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N], b[MAX_N];

int main() {
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];

	for(int i = 1; i<= N; i++) b[i] = a[i - 1] ^ a[i];
	
	int ans = 0;
	for(int i = 1; i <= N - K + 1; i++) {
		if(b[i]) {
			b[i + K] ^= 1;
			ans++;
		}
	}
	
	for(int i = N - K + 2; i <= N; i++) {
		if(b[i]) {
			cout << "Insomnia" << '\n';
			return 0;
		}
	}
	cout << ans << '\n';

	return 0;
}
