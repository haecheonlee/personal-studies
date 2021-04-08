/* reference: https://www.programmersought.com/article/87051177160/ */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 10;

int p[MAX_N], b[MAX_N];

int main() {
	int N; cin >> N;

	for(int i = 1; i < N; i++) {
		int x; cin >> x;
		p[i] = x + p[i - 1];
	}
	for(int i = 0; i < N; i++) b[i] = p[i];
	sort(p, p + N);
	
	bool flag = 1;
	for(int i = 0; i < N - 1; i++) {
		if(p[i] + 1 == p[i + 1]) continue;
		flag = 0;
		break;
	}

	if(flag) {
		int k = 1 - p[0];
		for(int i = 0; i < N; i++) cout << b[i] + k << ' ';
	} else {
		cout << -1 << '\n';
	}
	
	return 0;
}
