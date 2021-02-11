#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

vector<int> primes;
bool chk[MAX];

int main() {
	for(int i = 2; i < MAX; i++) {
		if(!chk[i]) {
			primes.push_back(i);
			for(int j = i + i; j < MAX; j += i) chk[j] = 1;
		}
	}
	
	int N;
	while(cin >> N) {
		if(N == 0) break;

		int ans = 1;
		for(auto& p : primes) {
			int x = 1;
			while(N % p == 0) {
				N /= p;
				x *= p;
			}
			
			if(x != 0) ans *= (x - (x / p));
		}
		
		if(N != 1) ans *= (N - 1);
		cout << ans << '\n';
	}
	
	return 0;
}
