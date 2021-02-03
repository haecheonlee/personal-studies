#include <iostream>

using namespace std;

int main() {
	long long N; cin >> N;
	
	if(N == 0) cout << 0 << '\n';
	else if(N & 1) cout << (N + 1) / 2 << '\n';
	else cout << N + 1 << '\n';

	return 0;
}
