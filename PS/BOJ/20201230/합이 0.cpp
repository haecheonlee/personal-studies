/* reference: dotorya */

#include <iostream>

using namespace std;

const int MAX_N = 1e4 + 1;
const int MAX = 4e4 + 1;

int a[MAX_N];
long long cnt[MAX];

int main() {
	int N;
	cin >> N;

	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];

	long long ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += cnt[20000 - a[i]];
		for(int j = 1; j < i; j++) cnt[20000 + a[i] + a[j]]++;
	}
	cout << ans << '\n';

	return 0;
}
