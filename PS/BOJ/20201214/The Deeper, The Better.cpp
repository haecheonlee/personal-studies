#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	int ans = 0;
	vector<char> a;
	for(int i = 0; i < (int)s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			int tmp = 0;
			for(auto& p : a) {
				if(p == '(') tmp += 1;
				if(p == '{') tmp += 2;
				if(p == '[') tmp += 3;
			}
			ans = max(ans, tmp);
		} else if(s[i] == '(') {
			a.push_back('(');
		} else if(s[i] == '{') {
			a.push_back('{');
		} else if(s[i] == '[') {
			a.push_back('[');
		} else {
			a.pop_back();
		}
	}
	cout << ans << '\n';

	return 0;
}
