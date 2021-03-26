#include <iostream>

using namespace std;

const int MAX_N = 2e2 + 10;

int x[MAX_N], y[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		bool L = 0, R = 0, U = 0, D = 0;
		for(int j = 0; j < N; j++) {
			if(i == j) continue;
			if(x[i] == x[j] && y[i] < y[j]) U = 1;
			if(x[i] == x[j] && y[i] > y[j]) D = 1;
			if(y[i] == y[j] && x[i] < x[j]) R = 1;
			if(y[i] == y[j] && x[i] > x[j]) L = 1;
		}
		
		ans += (U && D && R && L);
	}
	cout << ans << '\n';
	
	return 0;
}
