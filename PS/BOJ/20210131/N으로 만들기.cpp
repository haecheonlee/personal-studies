#include <iostream>
#include <map>

using namespace std;

map<string,int> m;

int go(string s) {
	if(m.find(s) != m.end()) return m[s];
	if(s.size() == 1) return 1;

	m[s] = 0;
	string L = s.substr(0, s.size() - 1);
	string R = s.substr(1, s.size() - 1);
	
	m[s] += go(L);
	if(L != R) m[s] += go(R);
	
	return m[s];
}

int main() {
	string s; cin >> s;
	cout << go(s) << '\n';

	return 0;
}
