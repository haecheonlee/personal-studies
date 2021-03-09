#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> p, ans;
bool check[20000];

void go(int idx, int sum) {
	if(idx >= (int)p.size()) {
		if(sum < 20000) check[sum] = 1;
		return;
	}
	
	go(idx + 1, sum + p[idx]);
	go(idx + 1, sum);
}

int main() {
	for(int i = 0; i < 11; i++) {
		int k = pow(3, i);
		p.push_back(k);
	}
	
	go(0, 0);
	for(int i = 0; i < 20000; i++) if(check[i]) ans.push_back(i);
	
	int Q; cin >> Q;
	while(Q--) {
		int N; cin >> N;
		cout << *lower_bound(ans.begin(), ans.end(), N) << '\n';
	}
	
	return 0;
}
