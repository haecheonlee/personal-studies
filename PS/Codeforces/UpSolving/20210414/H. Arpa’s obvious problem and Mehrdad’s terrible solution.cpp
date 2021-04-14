/* reference: gilcu3 */

#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];
int cnt[MAX_N];

int main() {
	int N, x; cin >> N >> x;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	long long ans = 0;
	for(int i = 1; i <= N; i++) {
		int k = x ^ a[i];
		if(k == a[i]) ans += cnt[a[i]] - 1;
		else if(k < MAX_N) ans += cnt[k];
	}
	cout << ans / 2 << '\n';
	
	return 0;
}
