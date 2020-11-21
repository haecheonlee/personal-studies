#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		if(N == 1) {
			cout << 0;
		} else if (N <= 3) {
			cout << (N == 2 ? 1 : 2);
		} else {
			cout << ((N & 1) ? 3 : 2);
		}

		cout << '\n';
	}

	return 0;
}
