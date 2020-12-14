/* reference: green55 */

#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

using namespace std;

const int MAX = 5e6 + 1;

int sieve[MAX];

void solve(int x) {
	while(sieve[x]) {
		cout << sieve[x] << ' ';
		x /= sieve[x];
	}
	
	cout << x << '\n';
}

int main() {
    fastio
    
	for(ll i = 2; i < MAX; i++) {
		if(sieve[i] == 0) {
			for(ll j = i * i; j < MAX; j += i) 
				if(sieve[j] == 0) sieve[j] = i;
		}
	}
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		solve(x);
	}
	
	return 0;
}
