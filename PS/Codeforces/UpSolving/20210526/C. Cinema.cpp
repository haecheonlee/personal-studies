#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 2e5 + 10;

map<int,int> mp;
int idx = 1;
int a[MAX_N], b[MAX_N], c[MAX_N], cnt[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(mp.find(a[i]) == mp.end()) mp[a[i]] = idx++;	
		cnt[mp[a[i]]]++;
	}

	int M; cin >> M;
	for(int i = 1; i <= M; i++) cin >> b[i];
	for(int i = 1; i <= M; i++) cin >> c[i];

	int ans = 1, s = cnt[mp[b[1]]], ss = cnt[mp[c[1]]];
	for(int i = 2; i <= M; i++) {
		int bx = cnt[mp[b[i]]], cx = cnt[mp[c[i]]];
		if(s < bx || (s == bx && ss < cx)) ans = i, s = bx, ss = cx;
	}
	
	cout << ans << '\n';
	
	return 0;
}
