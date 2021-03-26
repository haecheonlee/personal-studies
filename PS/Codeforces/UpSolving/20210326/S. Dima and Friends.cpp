#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	
	int sum = 0;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		sum += x;
	}
	
	int ans = 0;
	for(int k = 1; k <= 5; k++) {
		int p = (sum + k) % (N + 1);
		if(p != 1) ans++;
	}
	cout << ans << '\n';

	return 0;
}
