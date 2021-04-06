#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10;

vector<int> p[MAX_N];
char ans[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		p[x].push_back(i);
	}
	
	int A = 0, B = 0;
	
	for(int i = 1; i < MAX_N; i++) {
		int found = (int)p[i].size();
		if(found == 1) {
			if(A <= B) ans[p[i][0]] = 'A', A++;
			else ans[p[i][0]] = 'B', B++;
			p[i].pop_back();
		}
	}
	
	for(int i = 1; i < MAX_N; i++) {
		if(p[i].size()) {
			int found = (int)p[i].size();
			
			if(A == B) {
				for(auto& x : p[i]) ans[x] = 'A';
				if(found == 1) A++;
			} else if(A < B) {
				if(found >= 3 || found == 1) {
					ans[p[i][0]] = 'A';
					A++;
					
					for(int j = 1; j < p[i].size(); j++) ans[p[i][j]] = 'B';
				} else {
					for(auto& x : p[i]) ans[x] = 'A';
				}
			} else if(B < A) {
				if(found >= 3 || found == 1) {
					ans[p[i][0]] = 'B';
					B++;
					
					for(int j = 1; j < p[i].size(); j++) ans[p[i][j]] = 'A';
				} else {
					for(auto& x : p[i]) ans[x] = 'B';
				}
			}
		}
	}
	
	if(A == B) {
		cout << "YES" << '\n';
		for(int i = 0; i < N; i++) cout << ans[i];
	} else {
		cout << "NO" << '\n';
	}
	
	return 0;
}
