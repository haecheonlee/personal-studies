#include <iostream>

using namespace std;

int main() {
	int x, y; cin >> x >> y;
	y--;

	x -= y;
	cout << (x < 0 || x & 1 || y < 0 || (y == 0 && x) ? "NO" : "YES") << '\n';
	
	return 0;
}
