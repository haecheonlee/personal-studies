#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int N, M;
		cin >> N >> M;

		if(N < M) swap(N, M);

		if(N == 0 && M == 0) {
			cout << 0 << '\n';
		} else if(M == 0) {
			cout << N + (N - 1) << '\n';
		} else {
			
			cout << (M * 2) + ((N - M) * 2) + (N - M >= 1 ? -1 : 0) << '\n';
		}
	}

	return 0;
}
