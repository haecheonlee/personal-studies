#include <iostream>

using namespace std;

int main() {
	string s, t;
	while(cin >> s >> t) {
		int pos = 0;
		for(auto& c : t) {
			if(s[pos] == c && pos < s.size()) pos++;
		}
		
		cout << (pos == s.size() ? "Yes" : "No") << '\n';
	}
	
	return 0;
}
