#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 2e5 + 1;

void solve() {
	int N;
	cin >> N; 

	priority_queue<ll> odd, even;
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;

		if(x&1) odd.push(x); else even.push(x);
	}

	ll A = 0, B = 0;
	for(int i = 1; i <= N; i++) {
		if(i&1) {
			// Alice (even)
			if(!odd.empty() && !even.empty() && odd.top() > even.top()) {
				odd.pop();
			} else if(!even.empty()) {
				A += even.top();
				even.pop();
			} else if(!odd.empty()) {
				odd.pop();
			}
				
		} else {
			// Bob (odd)
			if(!even.empty() && !odd.empty() && even.top() > odd.top()) {
				even.pop();
			} else if(!odd.empty()) {
				B += odd.top();
				odd.pop();
			} else if(!even.empty()) {
				even.pop();
			}
		}
	}

	if(A > B) cout << "Alice" << '\n';
	else if(A < B) cout << "Bob" << '\n';
	else cout << "Tie" << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
