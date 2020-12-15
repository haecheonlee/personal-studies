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

string ans[51];

int main() {
	for(int i = 1; i <= 9; i++) ans[i] = to_string(i);
	for(int i = 46; i <= 50; i++) ans[i] = to_string(-1);
	
	int K = 8, kk = 0;
	for(int i = 10; i <= 45; i++) {
		string s = "";
		s += kk + 1 + '0';
		
		for(int j = K + 1; j <= 9; j++) s += j + '0';
		ans[i] = s;

		kk++;
		if(kk == K) {
			K--;
			kk = 0;
		}
	}
	


	int T;
	cin >> T;

	while(T--) {
		int x;
		cin >> x;

		cout << ans[x] << '\n';
	}

	return 0;
}
