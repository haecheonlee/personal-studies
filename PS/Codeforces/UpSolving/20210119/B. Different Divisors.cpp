/* reference: YunGoon */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 3e4 + 1;

vector<int> primes;
bool check[MAX];

void solve() {
	int d;
	cin >> d;
	
	int a = *lower_bound(primes.begin(), primes.end(), d + 1);
	int b = *lower_bound(primes.begin(), primes.end(), a + d);
	
	cout << a * b << '\n';
}

int main() {
	int T;
	cin >> T;
	
	for(int i = 2; i < MAX; i++) {
		if(!check[i]) {
			primes.push_back(i);
			for(int j = 2; j * i < MAX; j++) 
				check[j * i] = true;
		}
	}
	
	while(T--) solve();
	
	return 0;
}
