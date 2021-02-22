#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3;

int a[MAX_N], b[MAX_N], c[MAX_N];
bool check[MAX_N];

int gcd(int A, int B) {
	return (B == 0 ? A : gcd(B, A % B));	
}

void solve() {
	int N; cin >> N;
	
	vector<int> a(N);
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		check[i] = 0;
	}
	sort(a.rbegin(), a.rend());

	b[0] = c[0] = a[0], check[0] = 1;
	for(int i = 1; i < N; i++) {
		int selected = -1, g = -1;
		for(int j = 0; j < N; j++) {
			if(check[j]) continue;
			int x = gcd(c[i - 1], a[j]);
			if(x > g) selected = j, g = x;
		}
		b[i] = a[selected], c[i] = g, check[selected] = 1; 
	}
	
	for(int i = 0; i < N; i++) cout << b[i] << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
