#include <iostream>
#include <vector>

using namespace std;

int main() {
	string p[4];
	for(int i = 0; i < 4; i++) cin >> p[i];

	vector<int> ans;
	for(int i = 0; i < 4; i++) {
		int L = p[i].size() - 2;

		int S = 0, G = 0;
		for(int j = 0; j < 4; j++) {
			if(i == j) continue;

			int LL = p[j].size() - 2;
			if(L * 2 <= LL) S++;
			if(L >= LL * 2) G++;
		}

		if(S >= 3 || G >= 3) ans.push_back(i);
	}

	if(ans.size() == 1) cout << (char)('A' + ans.back()) << '\n';
	else cout << "C";

	return 0;
}
