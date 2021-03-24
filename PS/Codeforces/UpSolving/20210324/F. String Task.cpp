#include <iostream>

using namespace std;

bool is_vowel(char x) {
	return x == 'a' || x == 'o' || x == 'y' || x == 'e' || x =='u' || x == 'i';
}

int main() {
	string s; cin >> s;
	
	string ans = "";
	for(int i = 0; i < (int)s.size(); i++) {
		s[i] |= (1 << 5);
		if(is_vowel(s[i])) continue;
		
		ans += ".";
		ans += s[i];
	}
	cout << ans << '\n';
	
	return 0;
}
