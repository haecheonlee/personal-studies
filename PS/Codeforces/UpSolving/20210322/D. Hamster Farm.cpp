#include <iostream>

using namespace std;

int main() {
	long long N, K; cin >> N >> K;
	
	long long idx = -1, need = -1, mx = -1;
	for(int i = 1; i <= K; i++) {
		long long x; cin >> x;
		
		long long p = (N / x) * x;
		if(p > mx) mx = p, idx = i, need = p / x;
	}
	cout << idx << ' ' << need << '\n';
	
	return 0;
}
