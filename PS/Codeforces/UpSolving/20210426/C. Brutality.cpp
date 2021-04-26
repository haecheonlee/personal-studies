/* reference: editorial */

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 10;

int a[MAX_N];

int main() {
	int N, K; cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> a[i];
	string s; cin >> s;

	ll ans = 0;
	for(int i = 0, j = 0; i < N; i = j) {
		while(j < N && s[i] == s[j]) j++;
		
		sort(a + i, a + j);
		for(int k = j - 1; k >= max(i, j - K); k--) ans += a[k];
	}
	cout << ans << '\n';

	return 0;
}
