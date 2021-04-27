#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	
	int sum = 0;
	vector<int> odd_neg, odd_pos, even_neg, even_pos;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		if(x & 1) {
			if(x > 0) odd_pos.push_back(x);
			else if(x < 0) odd_neg.push_back(abs(x));
		}
		if(x > 0) sum += x;
	}
	
	sort(odd_pos.begin(), odd_pos.end());
	sort(odd_neg.begin(), odd_neg.end());
	
	int bigger = 0;
	if(sum % 2 == 0) {
		// even
		bigger = (odd_pos.size() ? odd_pos[0] : 1e9);
		if(odd_neg.size()) bigger = min(bigger, odd_neg[0]);
	}
	cout << sum - bigger << '\n';
	
	return 0;
}
