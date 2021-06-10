#include <iostream>

using namespace std;

int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	
	for(int i = 0; i <= 10000; i++) {
		int t = a * i + b;
		if(t - d >= 0 && (t - d) % c == 0) {
			cout << t << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';

	return 0;
}
