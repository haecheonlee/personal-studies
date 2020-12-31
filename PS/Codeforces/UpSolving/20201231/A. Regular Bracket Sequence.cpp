#include <iostream>
#include <stack>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		string s;
		cin >> s;
		
		if(s.size() & 1) {
			cout << "NO\n";
		} else {
			if(s[0] == ')'|| s.back() == '(') cout << "NO\n";
			else cout << "YES\n";
		}
	}
	
	return 0;
}
