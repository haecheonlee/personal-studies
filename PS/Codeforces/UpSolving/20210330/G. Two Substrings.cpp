#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	
	bool AB = 0, BA = 0;
	for(int i = 0; i < s.size() - 1; i++) {
		if(!AB && s[i] == 'A' && s[i + 1] == 'B') AB = 1, i++;
		else if(!BA && s[i] == 'B' && s[i + 1] == 'A') BA = 1, i++;
		
		if(AB && BA) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	
	AB = BA = 0;
	for(int i = s.size() - 1; i >= 0; i--) {
		if(!AB && s[i] == 'A' && s[i - 1] == 'B') AB = 1, i--;
		else if(!BA && s[i] == 'B' && s[i - 1] == 'A') BA = 1, i--;
		
		if(AB && BA) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	
	cout << "NO" << '\n';
	
	return 0;
}
