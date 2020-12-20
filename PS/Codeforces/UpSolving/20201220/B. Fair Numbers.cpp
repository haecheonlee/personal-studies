#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>

#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

set<ll> get_digits(ll N) {
    ll x = N;
	while(x) {
		ll d = x % 10;
		x /= 10;
		if(d != 0 && N % d != 0) return false;
	}	

	return true;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		ll N;
		cin >> N;

		if(N <= 9) {
			cout << N << '\n';
		} else {
			while(1) { 
                if(chk(N)) {
                    cout << N << '\n';
                    break;
                }
				N++;
			}
		}
	}

	return 0;
}
