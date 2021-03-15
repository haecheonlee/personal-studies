/* reference: editorial */

#include <iostream>
#include <vector>

using namespace std;

const int WAIT = 0, ENTER = 1, LEFT = 2;
const int MAX_P = 1e6 + 1;

int state[MAX_P];

int main() {
	int N; cin >> N;
	
	vector<int> res, cur;
	int anyone = 0;
	
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		int p = abs(x);
		cur.push_back(p);
		
		if(x > 0) {
			if(state[p] != WAIT) {
				cout << -1 << '\n';
				return 0;
			} else {
				state[p] = ENTER;
				anyone++;
			}
		} else {
			if(state[p] != ENTER) {
				cout << -1 << '\n';
				return 0;
			} else {
				state[p] = LEFT;
				anyone--;
			}
		}
		
		if(anyone == 0) {
			res.push_back(cur.size());
			for(auto& x : cur) state[x] = WAIT;
			cur.clear();
		}
	}
	
	if(!cur.empty()) {
		cout << -1 << '\n';
	} else {
		cout << res.size() << '\n';
		for(auto& x : res) cout << x << ' ';
	}		

	return 0;
}
