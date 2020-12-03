#include <iostream>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, int> m;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		
		int L = s.find('.') + 1;
		string type = s.substr(L, (int)s.size() - L);
		m[type]++;
	}
	
	for(auto& s : m) cout << s.first << ' ' << s.second << '\n';
	
	return 0;
}
