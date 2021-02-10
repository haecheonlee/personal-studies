#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> pp;
string s[101];
bool check[101];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> s[i];
	
	for(int i = 0; i < N; i++) {
		if(check[i]) continue;
		for(int j = i + 1; j < N; j++) {
			if(check[j]) continue;
			
			bool is_pp = 1;
			for(int k = 0; k < M && is_pp; k++) {
				if(s[i][k] != s[j][M - 1 - k]) is_pp = 0;
			}
			
			if(is_pp) {
				check[i] = check[j] = 1;
				pp.push_back(s[i]);
			}
		}
	}
	
	string p;
	for(int i = 0; i < N; i++) {
		if(check[i]) continue;
		
		// if self-palindrome
		bool is_p = 1;
		for(int k = 0; k < M / 2 && is_p; k++) {
			if(s[i][k] != s[i][M - 1 - k]) is_p = 0; 
		}
		if(is_p && s[i].size() > p.size()) p = s[i];
	}

	if(pp.empty() && p.empty()) {
		cout << 0 << '\n';
	} else if(pp.empty()) {
		cout << p.size() << '\n';
		cout << p << '\n';	
	} else {
		string L = "", R = "";
		for(auto& x : pp) {	
			L = L + x;
			reverse(x.begin(), x.end());
			R = x + R;
		}
		cout << L.size() + p.size() + R.size() << '\n';
		cout << L + p + R << '\n';
	}

	return 0;
}
