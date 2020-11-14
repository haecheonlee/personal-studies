/* reference: newdeal's logic */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 3e3 + 1;

int N, K;
int d[MAX][MAX][2];
int a[MAX];

int go(int n, int k, int status) {
	if(n == N) return 0;

	int& ret = d[n][k][status];
	if(ret != -1) return ret;
	ret = 0;

	if(k == 0) {
		ret = max(ret, go(n + 1, k, 0));
	}
	else {
		if(status == 1) ret = max(go(n + 1, k - 1, 1) + a[n], go(n + 1, k, 0));
		else ret = max(go(n + 1, k - 1, 1), go(n + 1, k, 0));
	}

	return ret;
}

int main() {
	cin >> N >> K;

	for(int i = 0; i < N; i++) cin >> a[i];

	memset(d, -1, sizeof(d));
	cout << go(0, K, 0);

	return 0;
}
