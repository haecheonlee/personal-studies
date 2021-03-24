#include <iostream>

using namespace std;

int main() {
	int n, a, b; cin >> n >> a >> b;
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(i - 1 >= a && n - i <= b) ans++;
	}
	cout << ans << '\n';

	return 0;
}
