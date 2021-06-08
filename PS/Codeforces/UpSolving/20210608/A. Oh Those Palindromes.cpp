/* reference: editorial */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	
	sort(s.begin(), s.end());
	cout << s << '\n';
	
	return 0;
}
