#include <iostream>
#include <algorithm>

using namespace std;

string s[101];

bool cmp(const string& l, const string& r) {
	return l.size() < r.size();
}

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> s[i];
	sort(s, s + N, cmp);
	
	bool is_good = 1;
	for(int i = 1; i < N; i++) {
		if(s[i].find(s[i - 1]) == string::npos) {
			is_good = 0;
			break;
		}
	}
	
	if(is_good) {
		cout << "YES" << '\n';
		for(int i = 0; i < N; i++) cout << s[i] << '\n';
	} else {
		cout << "NO" << '\n';
	}
	
	return 0;
}
