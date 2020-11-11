/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;

const int MAX = 1e2 + 1;

bool check[MAX][MAX], d[MAX][MAX];

bool go(int n, int m) {
	if(check[n][m]) return d[n][m];
	check[n][m] = true;
	d[n][m] = false;

	for(int i = 1; i < m; i++) {
		if(go(i, m - i) == false) d[n][m] = true;
	}

	for(int i = 1; i < n; i++) {
		if(go(n - i, i) == false) d[n][m] = true;
	}

	return d[n][m];
}

int main() {
	int N, M;
	cin >> N >> M;

	bool ans = go(N, M);
	
	cout << (ans ? 'A' : 'B');

	return 0;
}
