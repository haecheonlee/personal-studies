/* reference: codeplus/baekjoon */

#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 5e2;

int N;
int d[MAX_N][MAX_N];
int a[MAX_N][MAX_N];

int go(int l, int r) {
	int& ret = d[l][r];
	if(ret) return ret;
	
	int nxt = max(l, r) + 1;
	if(nxt == N) return 0;
	
	return ret = min(go(nxt, r) + a[nxt][l], go(l, nxt) + a[r][nxt]);
}

int main() {
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) 
			cin >> a[i][j];
	}
	cout << go(0, 0) << '\n';

	return 0;
}
