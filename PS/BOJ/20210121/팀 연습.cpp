#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int N, K;
int d[MAX_N][11][2][2];

int go(int n, int a, int b, int c) {
	if(n == N) return a == 0 && c != 0;
	
	int& ret = d[n][a][b][c];
	if(ret != -1) return ret;
	ret = 0;
	
	// a solved
	if(K) {
		ret += go(n + 1, (a + 1) % K, 0, c);
		ret %= MOD;
	}
	
	// b solved
	if(!b) {
		ret += go(n + 1, a, 1, c);
		ret %= MOD;
	}
	
	// c solved
	ret += go(n + 1, a, 0, 1);
	ret %= MOD;
	
	return ret;
}

int main() {
	cin >> N >> K;

	memset(d, -1, sizeof(d));
	cout << go(0, 0, 0, 0) << '\n';
	
	return 0;
}
