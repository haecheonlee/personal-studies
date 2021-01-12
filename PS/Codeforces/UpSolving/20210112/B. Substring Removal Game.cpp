#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	string s;
	cin >> s;
	
	vector<int> a;
	int L = (int)s.size();
	for(int i = 0; i < L; i++) {
		if(s[i] == '1') {
			int j = i;
			while(j < L && s[j] == '1') j++;
			a.push_back(j - i);
			i = j - 1;
		}
	}
	
	sort(a.rbegin(), a.rend());
	
	int ans = 0;
	for(int i = 0; i < (int)a.size(); i++) {
		if(!(i&1)) ans += a[i];
	}
	cout << ans << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
