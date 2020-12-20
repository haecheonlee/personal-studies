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

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		string s;
		cin >> s;

		int cnt = 0;
		for(int i = N - 1; i >= 0 && !cnt; i--) {
			if(s[i] == ')') {
				while(i >= 0 && s[i--] == ')') cnt++;
			}
		}
		
		int rem = N - cnt;
		cout << (cnt > rem ? "YES" : "NO") << '\n';
	}

	return 0;
}
