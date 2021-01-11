/* reference: editorial */

#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 51;

int a[MAX_N];

void solve() {
	int N;
	cin >> N;
	
	ll sumOdd = 0, sumEven = 0;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		
		if(i&1) sumOdd += a[i];
		else sumEven += a[i];
	}

	ll sum = sumOdd + sumEven;
	sumOdd *= 2, sumEven *= 2;
	if(sumOdd <= sum) {
		for(int i = 1; i <= N; i++) 
			cout << (i & 1 ? 1 : a[i]) << ' ';
	} else if(sumEven <= sum) {
		for(int i = 1; i <= N; i++) 
			cout << (!(i & 1) ? 1 : a[i]) << ' ';
	}
	cout << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
