#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
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

		string R, B;
		cin >> R >> B;

		int r = 0, b = 0;
		for(int i = 0; i < N; i++) {
			if(R[i] > B[i]) r++;
			else if(R[i] < B[i]) b++;
		}

		if(r == b) cout << "EQUAL" << '\n';
		else if(r < b) cout << "BLUE" << '\n';
		else if(r > b) cout << "RED" << '\n';
	}

	return 0;
}
