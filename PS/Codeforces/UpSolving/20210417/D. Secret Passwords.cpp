#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 10;

string s[MAX_N];
int p[26];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) p[y] = x;
}

int main() {
	int N; cin >> N;
	
	for(int i = 0; i < 26; i++) p[i] = i;
	for(int i = 0; i < N; i++) {
		cin >> s[i];
		
		int start = s[i][0] - 'a';
		for(int k = 0; k < s[i].size(); k++) Union(start, s[i][k] - 'a');
	}
	
	set<int> ans;
	for(int i = 0; i < N; i++) {
		for(auto& ss : s[i]) ans.insert(Find(p[ss - 'a']));
	}
	cout << ans.size() << '\n';
	
	return 0;
}
