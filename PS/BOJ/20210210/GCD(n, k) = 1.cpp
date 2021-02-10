/* Euler's phi function */

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;

vector<int> primes;
bool check[MAX];

int main() {
	for(int i = 2; i < MAX; i++) {
		if(!check[i]) {
			primes.push_back(i);
			for(int j = 2; j * i < MAX; j++) check[i * j] = 1;
		}
	}
	
	long long N; cin >> N;
	long long ans = 1;
	
	for(auto& p : primes) {
		long long x = 1;
		while(N % p == 0) {
			N /= p;
			x *= p;
		}
		
		if(x != 0) ans *= (x - (x / p));
	}

	if(N != 1) ans *= (N - 1);
	cout << ans << '\n';
	
	return 0;
}
