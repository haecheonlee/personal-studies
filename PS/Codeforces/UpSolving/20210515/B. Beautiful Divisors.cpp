#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 10;

int main() {
	int N; cin >> N;
	
	vector<int> list;
	int now = 1, L = 2;
	while(now <= MAX_N) {
		list.push_back(now);
		now <<= 1;
		now |= (1 << L);
		L += 2;
	}
	
	int ans = 0;
	for(auto& x : list) if(N % x == 0) ans = x;
	cout << ans << '\n';
	
	return 0;
}
