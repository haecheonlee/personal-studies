#include <iostream>

using namespace std;

int main() {
	int a, b; cin >> a >> b;
	
	cout << ((a == 0 && b == 0) || abs(a - b) > 1 ? "NO" : "YES") << '\n';
	
	return 0;
}
