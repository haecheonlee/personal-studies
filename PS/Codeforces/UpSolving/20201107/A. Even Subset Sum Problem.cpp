#include <iostream>
#include <vector>

#define sz(x) (int)(x.size())

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		vector<int> odd, even;
		for(int i = 1; i <= N; i++) {
			int x;
			cin >> x;

			if(x&1) odd.push_back(i);
			else even.push_back(i);
		}

		if(!even.empty()) {
			cout << 1 << '\n' << even[0] << '\n';
		} else {
			if(sz(odd) <= 1) cout << -1 << '\n';
			else cout << 2 << '\n' << odd[0] <<' ' << odd[1] << '\n'; 
		}
	}

	return 0;
}
