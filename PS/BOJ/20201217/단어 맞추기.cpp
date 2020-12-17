#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		string s;
		cin >> s;
		
		string ordered = s;
		sort(ordered.rbegin(), ordered.rend());
		
		if(ordered == s) {
			cout << ordered << '\n';
		} else {
			next_permutation(s.begin(), s.end());
			cout << s << '\n';
		}
	}
	
	return 0;
}
