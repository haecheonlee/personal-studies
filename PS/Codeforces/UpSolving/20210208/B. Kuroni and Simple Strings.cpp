#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e3 + 1;

bool check[MAX];

int main() {
	string s; cin >> s;

	vector<vector<int>> ans;
	while(1) {
		int L = 0, R = s.size() - 1;
		vector<int> p;
		
		while(L < R) {
			bool LF = 0;
			for(int i = L; i < R; i++) {
				if(check[i]) continue;
				if(s[i] == '(') {
					LF = 1;
					L = i;
					break;
				}
			}
			
			bool RF = 0;
			for(int i = R; i > L; i--) {
				if(check[i]) continue;
				if(s[i] == ')') {
					RF = 1;
					R = i;
					break;
				}
			}
			
			if(!LF || !RF) break;
			if(L < R) {
				check[L] = check[R] = 1;
				p.push_back(L);
				p.push_back(R);
			}
		}
		
		if(p.empty()) break;
		else ans.push_back(p);
	}

	int total = 0;
	for(int i = 0; i < ans.size(); i++) total += ans[i].size();

	if(ans.size()) {
		cout << ans.size() << '\n';
		cout << total << '\n';
		for(int i = 0; i < s.size(); i++) {
			if(check[i]) cout << i + 1 << ' ';
		}
	} else {
		cout << 0 << '\n';
	}
	
	return 0;
}
