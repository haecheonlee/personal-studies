/* reference: editorial */

#include <iostream>

using namespace std;

const int MAX = 3e5 + 10;

int a[MAX], b[MAX];
int cnt[MAX][2];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < M; i++) cin >> a[i] >> b[i];

	for(int i = 0; i < M; i++) {
		if(!(a[i] == a[0] || b[i] == a[0])) {
			cnt[a[i]][0]++;
			cnt[b[i]][0]++;
		} else {
			cnt[a[0]][0]++;
		}
		
		if(!(a[i] == b[0] || b[i] == b[0])) {
			cnt[a[i]][1]++;
			cnt[b[i]][1]++;
		} else {
			cnt[b[0]][1]++;
		}
	}
	
	for(int i = 1; i <= N; i++) {
		if(i != a[0] && cnt[i][0] + cnt[a[0]][0] == M) {
			cout << "YES" << '\n';
			return 0;
		}
		
		if(i != b[0] && cnt[i][1] + cnt[b[0]][1] == M) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';

	return 0;
}
