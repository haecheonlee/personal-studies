#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve() {
	int N;
	cin >> N;

	string s;
	cin >> s;

	vector<int> two, zero;
	for(int i = 0; i < N; i++) {
		if(s[i] == '2') two.push_back(i);
		else if(s[i] == '0') zero.push_back(i);
	}

	for(int i = 0; i < sz(two); i++) {
		for(int j = 0; j < sz(zero); j++) {
			if(zero[j] < two[i]) continue;
			for(int ii = i + 1; ii < sz(two); ii++) {
				if(two[ii] < zero[j]) continue;
				for(int jj = j + 1; jj < sz(zero); jj++) {
					if(zero[jj] < two[ii]) continue;
					int gap = 0;

					if(two[i] != 0) gap++;
					if(zero[j] - two[i] != 1) gap++;
					if(two[ii] - zero[j] != 1) gap++;
					if(zero[jj] - two[ii] != 1) gap++;
					if(zero[jj] != N - 1) gap++;
					
					if(gap <= 1) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}

	cout << "NO\n";
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
