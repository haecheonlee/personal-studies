#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	
	if(N & 1) {
		cout << 0 << '\n';
	} else {
		int ans = N / 4;
		if(N % 4 == 0) ans--;
		cout << ans << '\n';
	}
	
	return 0;
}
