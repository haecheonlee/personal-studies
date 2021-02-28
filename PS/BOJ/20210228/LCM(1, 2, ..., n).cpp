/* reference: https://seokjin2.tistory.com/16 */

#include <iostream>
#include <vector>

using namespace std;

const long long MOD = (1LL << 32);
const int MAX = 1e8 + 1;

vector<int> primes;
bool check[MAX];

int main() {
	for(int i = 2; i * i < MAX; i++) {
		if(!check[i]) {
			for(int j = i + i; j < MAX; j += i) check[j] = 1;
		}
	}
	
	int N; cin >> N;
	for(int i = 2; i <= N; i++) {
		if(!check[i]) primes.push_back(i);
	}
	
	long long ans = 1;
	for(auto& p : primes) {
		long long power = p;
		while(power * p <= N) power *= p;
		ans = (ans * power) % MOD;
	}
	cout << ans << '\n';
	
	return 0;
}
