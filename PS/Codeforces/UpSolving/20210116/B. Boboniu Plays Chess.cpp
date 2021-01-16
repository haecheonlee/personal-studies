/* reference: editorial(https://codeforces.com/blog/entry/81355) */

#include <iostream>

using namespace std;

int N, M, sx, sy;

void f(int i, int j) {
	cout << (i + sx - 2) % N + 1 << ' ' << (j + sy - 2) % M + 1 << '\n';
}

int main() {
	cin >> N >> M >> sx >> sy;
	
	for(int i = 1; i <= N; i++) {
		if(i & 1) for(int j = 1; j <= M; j++) f(i, j);
		else for(int j = M; j >= 1; j--) f(i, j);
	}

	return 0;
}
