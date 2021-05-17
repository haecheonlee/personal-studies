#include <iostream>

using namespace std;

const int MAX_N = 3e5 + 10;

int a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(a[i] != a[1]) ans = max(ans, i - 1);
		if(a[i] != a[N]) ans = max(ans, N - i);
	}
	cout << ans << '\n';

	return 0;
}
