#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long N; cin >> N;
	
	long long sum = (N * (N + 1)) / 2;
	if(sum & 1) {
		cout << 1 << '\n';
		if(sum <= 2) {
			cout << 1 << ' ' << N;
		} else {
			sum /= 2;
			vector<int> ans;
			for(int i = N; i >= 1; i--) {
				if(sum - i >= 0) {
					ans.push_back(i);
					sum -= i;
				}
			}
			cout << ans.size() << ' ';
			for(auto& x : ans) cout << x << ' ';
		}
	} else {
		cout << 0 << '\n';
		if(N <= 3) {
			cout << 1 << ' ' << N << '\n';
		} else {
			sum /= 2;
			vector<int> ans;
			for(int i = N; i >= 1; i--) {
				if(sum - i >= 0) {
					ans.push_back(i);
					sum -= i;
				}
			}
			cout << ans.size() << ' ';
			for(auto& x : ans) cout << x << ' ';
		}

	}
	
	return 0;
}
