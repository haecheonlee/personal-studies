#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 1;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		
		a[x] = i;
	}
	
	int L = a[1], R = a[1];
	for(int i = 1; i <= N; i++) {
		if(i == 1) {
			cout << 1;
		} else {
			int x = a[i];
			
			if(L <= a[i] && a[i] <= R) {
				cout << (R - L + 1 <= i ? 1 : 0);
			} else {
				if(a[i] < L) L = a[i];
				else if(a[i] > R) R = a[i];
				
				cout << (R - L + 1 <= i ? 1 : 0);
			}
		}
	}
	cout << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
