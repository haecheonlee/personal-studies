#include <iostream>

using namespace std;

int lower, upper, digit;

bool is_digit(char x) {
	return x >= '0' && x <= '9';
}

bool is_lower(char x) {
	return x >= 'a' && x <= 'z';
}

bool is_upper(char x) {
	return x >= 'A' && x <= 'Z';
}

void solve() {
	string s; cin >> s;
	lower = upper = digit = 0;
	for(auto& x : s) {
		if(is_lower(x)) lower++;
		else if(is_upper(x)) upper++;
		else if(is_digit(x)) digit++;
	}
	
	for(int i = 0; i < s.size(); i++) {
		if(digit == 0) {
			if(is_lower(s[i]) && lower >= 2) s[i] = '0', digit++, lower--;
			else if(is_upper(s[i]) && upper >= 2) s[i] = '0', digit++, upper--;
		} else if(lower == 0) {
			if(is_digit(s[i]) && digit >= 2) s[i] = 'a', lower++, digit--;
			else if(is_upper(s[i]) && upper >= 2) s[i] = 'a', lower++, upper--;
		} else if(upper == 0) {
			if(is_lower(s[i]) && lower >= 2) s[i] = 'A', upper++, lower--;
			else if(is_digit(s[i]) && digit >= 2) s[i] = 'A', upper++, digit--;
		}
	}
	
	cout << s << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
}
