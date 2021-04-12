#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];
int p[MAX_N];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i]; 

	for(int i = 1; i <= M; i++) {
		int l, r, c; cin >> l >> r >> c;
		p[l] += c;
		p[r + 1] -= c;
	}
	
	for(int i = 1; i <= N; i++) {
		p[i] += p[i - 1];
		cout << a[i] + p[i] << ' ';
	}

	return 0;
}
