/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 51;
const int INF = 1e6;

pii d[MAX * MAX][MAX][1 << 4];
string a[4];
string s;

pii go(int index, int covered, int mask) {
	if(mask == 0) return make_pair(0, 0);
	
	auto& ret = d[index][covered][mask];
	if(ret.first != -1) return ret;
	
	ret = make_pair(INF, -INF);
	if(index == s.size()) return ret;

	// skip
	ret = go(index + 1, max(0, covered - 1), mask);
	
	// use
	for(int i = 0; i < 4; i++) {
		if(mask & (1 << i)) {
			if(s.substr(index, a[i].size()) == a[i]) {
				int nxt = 0;
				if(a[i].size() > covered) nxt = (int)a[i].size() - covered;
				
				auto tmp = go(index, max(covered, (int)a[i].size()), mask - (1 << i));
				ret = make_pair(min(tmp.first + nxt, ret.first), max(tmp.second + nxt, ret.second));
			}
		}
	}
	
	return ret;
}

int main() {
	cin >> s;
	for(int i = 0; i < 4; i++) cin >> a[i];
	sort(a, a + 4);
	
	memset(d, -1, sizeof(d));
	auto ans = go(0, 0, 15);
	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}
