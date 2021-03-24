#include <iostream>

using namespace std;

bool is_lucky(int n) {
	while(n) {
		int x = n % 10;
		if(x != 4 && x != 7) return false;
		n /= 10;
	}
	
	return true;
}

int main() {
	int n; cin >> n;
	
	for(int i = 1; i <= n; i++) {
		if(is_lucky(i) && n % i == 0) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';

	return 0;
}
