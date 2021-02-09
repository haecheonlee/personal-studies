#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	
	if(n == 0) {
		cout << 1 << '\n';
	} else {
		int x = n % 4;
		if(x == 0) cout << 6 << '\n';
		else if(x == 1) cout << 8 << '\n';
		else if(x == 2) cout << 4 << '\n';
		else if(x == 3) cout << 2 << '\n';
	}
}
