#include <iostream>

using namespace std;

int main() {
	long long N; cin >> N;
	cout << (N & 1 ? 0 : (1LL * 1 << ((N - 4) / 2 + 2)));

	return 0;
}
