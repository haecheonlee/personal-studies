#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;

	vector<char> ans;
	for(int i = 0; i < N - 1; i += 2) {
		if(s[i] == s[i + 1]) {
			i--;
		} else {
			ans.push_back(s[i]);
			ans.push_back(s[i + 1]);
		}
	}
	
	cout << N - ans.size() << '\n';
	for(auto& x : ans) cout << x;
	
	return 0;
}
