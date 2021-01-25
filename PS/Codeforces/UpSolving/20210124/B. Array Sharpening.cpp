/* reference: editorial */

#include <iostream>

using namespace std;

const int MAX_N = 3e5 + 1;

int a[MAX_N];
bool check[MAX_N];

void solve() {
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++) cin >> a[i];
	
	int L = -1, R = N;
	for(int i = 0; i < N; i++) {
		if(a[i] < i) break;
		L = i;
	}
	
	for(int i = N - 1; i >= 0; i--) {
		if(a[i] < (N - 1) - i) break;
		R = i;
	}
	
	cout << (R <= L ? "Yes" : "No") << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
