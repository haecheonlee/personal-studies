#include <iostream>

using namespace std;

int removeZero(int x) {
	int xx = 0;
	int L = 1;
	while(x) {
		int r = x % 10;
		if(r) xx += r * L, L *= 10;
		x /= 10;
	}

	return xx;
}

int main() {
	int a, b; cin >> a >> b;
	int c = a + b;

	int aa = removeZero(a);
	int bb = removeZero(b);
	int cc = removeZero(c);

	cout << (aa + bb == cc ? "YES" : "NO") << '\n';
	
	return 0;
}
