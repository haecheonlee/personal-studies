#include <iostream>
#include <cstring>
#include <algorithm>

#define sz(x) (int)(x.size())

using namespace std;

const int MAX = 51;
const int INF = 1e9;

int N;
string s = "";
string a[MAX];
int d[MAX];

int go(int L) {
	if(L == sz(s)) return 0;

	int& ret = d[L];
	if(d[L] != -1) return ret;
	ret = INF;

	for(int i = 0; i < N; i++) {
		if(L + sz(a[i]) <= sz(s)) {
			string as = a[i];
			string ns = s.substr(L, sz(a[i]));

			int cost = 0;
			for(int j = 0; j < sz(a[i]); j++) {
				if(ns[j] != a[i][j]) cost++;
			}

			sort(as.begin(), as.end());
			sort(ns.begin(), ns.end());

			if(ns == as) ret = min(ret, go(L + sz(a[i])) + cost);
		}
	}

	return ret;
}

int main() {
	cin>>s>>N;

	for(int i = 0; i < N; i++) cin>>a[i];

	memset(d, -1, sizeof(d));
	int ans = go(0);
	cout<<(ans == INF ? -1 : ans);

	return 0;
}
