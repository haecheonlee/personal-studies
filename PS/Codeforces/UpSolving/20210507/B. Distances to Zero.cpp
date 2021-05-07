#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 10;
const int INF = 1e9;

int a[MAX_N];
int p[MAX_N], rp[MAX_N];

int main() {
	int N; cin >> N;
	
	p[0] = rp[N + 1] = INF;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		p[i] = rp[i] = INF;	
	}

	// forward
	for(int i = 1; i <= N; i++) {
		if(i == 1) p[i] = (a[i] == 0 ? i : INF);
		else p[i] = (a[i] == 0 ? i : p[i - 1]);
	}
	
	for(int i = N; i >= 1; i--) {
		if(i == N) rp[i] = (a[i] == 0 ? i : INF);
		else rp[i] = (a[i] == 0 ? i : rp[i + 1]);
	}
	
	for(int i = 1; i <= N; i++) {
		int l = abs(i - p[i]);
		int r = abs(rp[i] - i);
		
		cout << min(l, r) << ' ';
	}
	
	return 0;
}
