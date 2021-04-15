#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 10;

bool check[MAX_N];
int ans[MAX_N][MAX_N];

void solve() {
	int N; cin >> N;
	
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= N; j++) 
			ans[i][j] = 1;
	
	if(check[N]) {
		// if not prime
		int need = 1;
		while(check[N + need - 1] || !check[need]) need++;
		
		for(int i = 1; i <= N; i++) ans[i][i] = need;
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	for(int i = 2; i < MAX_N; i++) 
		for(int j = i + i; j < MAX_N; j += i) 
			check[j] = 1;
	
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
