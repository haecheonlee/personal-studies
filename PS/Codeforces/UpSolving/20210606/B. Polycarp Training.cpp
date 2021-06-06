#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	int ans = 0;
	int k = 1;
	for(int i = 0; i < N; i++) {
		if(a[i] >= k) ans = k++;
	}
	cout << ans << '\n';
	
	return 0;
}
