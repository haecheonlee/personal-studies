/* reference: BledDest */

#include <iostream>
#include <set>

using namespace std;

int f(int x) {
	x += 1;
	while(x % 10 == 0) x /= 10;
	return x;
}

int main() {
	int n;
	cin >> n;

	set<int> a;

	while(a.find(n) == a.end()) {
		a.insert(n);
		n = f(n);
	}

	cout << a.size();
	

	return 0;
}
