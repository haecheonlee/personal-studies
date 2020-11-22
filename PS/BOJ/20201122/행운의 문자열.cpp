#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	sort(s.begin(), s.end());
	
	int ans = 0;
	
	do {
		int L = (int)(s.size());
		bool is_good = true;
		for(int i = 0; i < L; i++) {
			if(i > 0 && s[i] == s[i - 1]) is_good = false;
			if(i < L && s[i] == s[i + 1]) is_good = false;
		}
		
		if(is_good) ans++;
	} while(next_permutation(s.begin(), s.end()));
	
	cout << ans << '\n';
	
	return 0;
}
