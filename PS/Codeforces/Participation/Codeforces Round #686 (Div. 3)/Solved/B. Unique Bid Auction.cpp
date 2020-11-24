#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		pii cnt[N + 1];
		for(int i = 1; i <= N; i++) cnt[i].first = cnt[i].second = 0;

		for(int i = 1; i <= N; i++) {
			int x;
			cin >> x;

			cnt[x].first++;
			cnt[x].second = i;
		}

		int ans = -1;
		for(int i = 1; i <= N; i++) {
			if(cnt[i].first == 1) {
				ans = cnt[i].second;
				break;	
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
