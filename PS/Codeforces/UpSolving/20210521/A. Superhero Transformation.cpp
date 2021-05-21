#include <iostream>

using namespace std;

bool is_vowel(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';	
}

int main() {
	string s, t; cin >> s >> t;
	bool flag = s.size() == t.size();
	
	if(!flag) {
		cout << "No" << '\n';
	} else {
		for(int i = 0; i < s.size(); i++) {
			bool ss = is_vowel(s[i]), tt = is_vowel(t[i]);
			if(ss != tt) flag = 0;
		}
		cout << (flag ? "Yes" : "No") << '\n';
	}
	
	return 0;
}
