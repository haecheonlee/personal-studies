#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];

	int ans = 1;	
	for(int R = 0, L = 0; R < N; R++) {
		ans = max(ans, R - L + 1);
		if(R < N - 1 && a[R] * 2 < a[R + 1]) L = R + 1;
	}	

	cout << ans << '\n';

	return 0;
}
