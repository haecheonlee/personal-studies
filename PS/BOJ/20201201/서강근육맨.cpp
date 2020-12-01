#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	long long a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	long long ans = a[N - 1];
	for(int i = 0; i < N / 2; i++) {
		if(N & 1) ans = max(ans, a[i] + a[N - 2 - i]);
		else ans = max(ans, a[i] + a[N - 1 - i]);
	}
	cout << ans;
	
	return 0;
}
