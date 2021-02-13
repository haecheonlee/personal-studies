#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int N; cin >> N;
	
	set<int> s;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	
	vector<int> p;
	for(auto it : s) p.push_back(it);
	
	if(p.size() == 1) {
		cout << 0 << '\n';
	} else {
		int D = p[1] - p[0];
		if(p.size() == 2) {
			if(D % 2 == 0) cout << D / 2 << '\n';
			else cout << D << '\n';
		} else {
			for(int i = 2; i < p.size(); i++) {
				if(p[i] - D != p[1]) {
					cout << -1 << '\n';
					return 0;
				}
			}
			cout << D << '\n';
		}
	}
	
	return 0;
}
