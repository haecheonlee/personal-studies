/* reference: editorial */

#include <iostream>
#include <set>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		set<int> nums;
		for(int i = 2; i * i <= N; i++) {
			if(N % i == 0) {
				nums.insert(i);
				N /= i;
				break;
			}
		}

		for(int i = 2; i * i <= N; i++) {
			if(N % i == 0 && !nums.count(i)) {
				nums.insert(i);
				N /= i;
				break;
			}
		}

		if(nums.size() + 1 < 3 || nums.count(N)) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			for(auto& x : nums) cout << x << ' ';
			cout << N << '\n';
		}
	}
}
