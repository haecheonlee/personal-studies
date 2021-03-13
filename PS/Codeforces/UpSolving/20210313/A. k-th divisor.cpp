#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long N, K; cin >> N >> K;
	
	vector<long long> d;
	for(long long i = 1; i * i <= N; i++) {
		if(N % i == 0) {
			long long j = N / i;
			
			d.push_back(i);
			if(i != j) d.push_back(j);
		}
	}
	sort(d.begin(), d.end());
	
	cout << (d.size() < K ? -1 : d[K - 1]) << '\n';

	return 0;
}
