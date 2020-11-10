#include <iostream>
#include <vector>

#define sz(x) (int)(x.size())

using namespace std;

int main() {
	string s;
	cin >> s;

	int N;
	cin >> N;

	vector<int> a, b;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '?') a.push_back(i);
		else if(s[i] == '*') b.push_back(i);
	}

	int left = sz(s) - sz(a) - sz(b);
	if(left == N) {
		for(int i = 0; i < sz(s); i++) {
			if(s[i] != '?' && s[i] != '*') cout << s[i];
		}
	} else {
		string ans = "";
		if(left > N) {
			if(left - N <= sz(a) + sz(b)) {
				int removed = left - N;
				for(int i = 0; i < sz(s); i++) {
					if((s[i + 1] == '?' || s[i + 1] == '*') && removed) {
						removed--;
						continue;
					}
					if(s[i] != '?' && s[i] != '*') ans += s[i];
				}
			}
		} else {
			if(sz(b)) {
				bool used = false;
				int need = N - left;
				for(int i = 0; i < sz(s); i++) {
					if(!used && s[i] == '*') {
						used = true;
						while(need--) ans += s[i - 1];
					}
					if(s[i] != '?' && s[i] != '*') ans += s[i];
				}
			}
		}
	
		cout << (ans == "" ? "Impossible" : ans);
	}

	return 0;
}
