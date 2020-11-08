#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		string s;
		cin >> s;
		
		s += '0';
		
		vector<int> a;
		for(int i = 0; i < (int)s.size(); i++) {
			if(s[i] == '1') a.push_back(i);
		}
		
		if(a.size() == 1 || a.empty()) {
			cout << 0 << '\n';
		} else {
			int ans = 0;
			for(int i = 0; i < a.size() - 1; i++) ans += a[i + 1]	- a[i] - 1;
			cout << ans << '\n';
		}
	}

	return 0;
}
