#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	string a, b;
	cin >> a >> b;

	if(a == b) {
		cout << 0 << '\n';
	} else {
		string s1 = a, s2 = b;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		if(s1 != s2) {
			cout << -1 << '\n';
		} else {
			vector<int> ans;
			for(int i = 0; i < N; i++) {
				if(a[i] == b[i]) continue;
				int idx = i + 1;
				while(a[idx] != b[i]) idx++;
				for(int j = idx; j > i; j--) {
					swap(a[j], a[j - 1]);
					ans.push_back(j);
				}	
			}

			cout << (int)ans.size() << '\n';
			for(auto& x : ans) cout << x << ' ';
		}
	}

	return 0;
}
