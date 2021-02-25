#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);

	int L = 1, R = N;
	int ans[N + 1];
	for(int i = 1; i <= N; i++) {
		if(i & 1) ans[L++] = a[i];
		else ans[R--] = a[i];
	}
	
	for(int i = 1; i <= N; i++) cout << ans[i] << ' ';

	return 0;
}
