#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;

vector<int> primes;
bool check[MAX];

int main() {
	check[0] = check[1] = 1;
	for(int i = 2; i * 4 < MAX; i++) {
		if(!check[i]) {
			primes.push_back(i);
			for(int j = i + i; j < MAX; j += i) check[j] = 1;
		}
	}

	int N; cin >> N;
	if(N < 7) {
		cout << -1 << '\n';
	} else {
		vector<int> ans;
		if(N & 1) {
			ans.push_back(2); ans.push_back(3);
			N -= 5;
			for(auto& x : primes) {
				if(!check[N - x]) {
					ans.push_back(x);
					ans.push_back(N - x);
					break;
				}
			}
		} else {
			int L = N / 2, R = N - L;
			if(L & 1 && R & 1) L -= 1, R += 1;
			for(auto& x : primes) {
				if(L > x && !check[L - x]) {
					ans.push_back(x); ans.push_back(L - x);
					break;
				}
			}
			
			for(auto& x : primes) {
				if(R > x && !check[R - x]) {
					ans.push_back(x); ans.push_back(R - x);
					break;
				}
			}
		}
		
		for(auto& x : ans) cout << x << ' ';
	}

	return 0;
}
