/* reference: editorial */

#include <iostream>

using namespace std;

int main() {
	int n, m; cin >> n >> m;

	for(int i = 0; i < 200; i++) cout << 9;
	for(int i = 0; i < 199; i++) cout << 0;
	cout << 1 << '\n';
	for(int i = 0; i < 200; i++) cout << 9;

	return 0;
}
