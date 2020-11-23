/* reference: editorial */

#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int n, k;
		cin >> n >> k;
		
		string a, b;
		cin >> a >> b;
		
		int have[26] {0};
		for(auto& c : a) have[c - 'a']++;
		
		int need[26] {0};
		for(auto& c : b) need[c - 'a']++;
		
		bool bad  = false;
		for(int i = 0; i < 26; i++) {
			if(have[i] < need[i] || (have[i] -= need[i]) % k) bad = true;
			have[i + 1] += have[i];
		}
		
		cout << (bad ? "No" : "Yes") << '\n';
	}
	
	return 0;
}
