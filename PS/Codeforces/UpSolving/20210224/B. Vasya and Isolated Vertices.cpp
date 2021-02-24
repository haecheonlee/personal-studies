#include <iostream>

using namespace std;

int main() {
	long long N, M; cin >> N >> M;

	long long E = 0, k = 0;
	for(int i = 1; i <= N; i++) {
		if(E >= M) break;
		E += k;
		k++;
	}

	long long mn = max(0LL, N - M * 2);
	long long mx = max(0LL, N - k);

	cout << mn << ' ' << mx << '\n';

	return 0;
}
