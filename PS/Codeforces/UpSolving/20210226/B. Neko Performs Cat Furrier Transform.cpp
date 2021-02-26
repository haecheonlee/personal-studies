#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x; cin >> x;
	
	vector<int> ans;
	int k = 0;
	while(k < 40) {
		int bit = 32 - __builtin_clz(x);
		int A = (1 << bit) - 1;
		
		if(x == A) break;
		if(!(k & 1)) {
			x ^= A;
			ans.push_back(bit);
		} else {
			x++;
		}
		
		k++;
	}
	
	cout << k << '\n';
	for(auto& x : ans) cout << x << ' ';
	
	return 0;
}
