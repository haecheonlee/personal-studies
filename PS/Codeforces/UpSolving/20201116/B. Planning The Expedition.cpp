/* reference: editorial */

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e2 + 1;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> a(MAX);
	for(int i = 0; i < M; i++) {
		int x;
		cin >> x;

		a[x]++;
	}

	for(int i = MAX; i >= 1; i--) {
		vector<int> aa(a);
		int k = 0;

		for(int j = 1; j <= N; j++) {
			while(aa[j] >= i) {
				k++;
				aa[j] -= i;
			}
		}

		if(k >= N) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << 0;

	return 0;
}
