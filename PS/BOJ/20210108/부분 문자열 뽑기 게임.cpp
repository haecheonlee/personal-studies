/* reference: https://redbinalgorithm.tistory.com/m/428?category=880024 */

#include <iostream>

#define sz(x) (int)(x.size())

using namespace std;

const int MAX_N = 1e6 + 1;

int d[MAX_N];

int solve(int n) {
	if(d[n] != 0) return d[n];
	if(n < 10) return d[n] = -1;
	
	int K = MAX_N;
	bool is_possible = false;
	
	string s = to_string(n);
	for(int i = 0; i < sz(s); i++) {
		for(int j = i, x = 0; j < sz(s); j++) {
			x = 10 * x + (s[j] - '0');
			if(x == 0 || n == x) continue;
			
			if(solve(n - x) == -1) {
				is_possible = true;
				K = min(K, x);
			}
		}
	}
	
	if(is_possible == false) return d[n] = -1;
	return d[n] = K;
}

int main() {
	int N;
	cin >> N;
	
	cout << solve(N) << '\n';
	
	return 0;
}
