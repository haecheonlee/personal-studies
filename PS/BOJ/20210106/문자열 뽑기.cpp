/* reference: https://github.com/kks227/BOJ/blob/master/8900/8913.cpp */

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> m;

bool go(string s) {
	auto it = m.find(s);
	if(it != m.end()) return it->second;
	
	if(s.size() == 0) return 1;
	if(s.size() == 1) return 0;
	
	bool ret = false;
	int L = 0, R;
	for(R = 0; R < s.size() && !ret; R++) {
		if(R == 0 || s[R] != s[R - 1]) {
			if(R - L > 1) ret |= go(s.substr(0, L) + s.substr(R));
			L = R;
		}
	}
	
	if(R - L > 1) ret |= go(s.substr(0, L));
	return m[s] = ret;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		string s;
		cin >> s;
		
		cout << go(s) << '\n';
	}
	
	return 0;
}
