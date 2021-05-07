/* https://www.youtube.com/watch?v=38hprbJjUOw&ab_channel=NealWu */

#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 10;

struct Group {
	int i, j, x, y;
};

int a[MAX_N];
 
void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	vector<Group> ans;
	
	int mv = 1e9 + 1, mi = -1;
	for(int i = 1; i <= N; i++) if(mv > a[i]) mv = a[i], mi = i;
	
	int far = 1;
	for(int j = mi - 1; j >= 1; j--) ans.push_back({mi, j, mv, mv + far++});
	
	far = 1;
	for(int j = mi + 1; j <= N; j++) ans.push_back({mi, j, mv, mv + far++});
	
	cout << ans.size() << '\n';
	for(auto& p : ans) cout << p.i << ' ' << p.j << ' ' << p.x << ' ' << p.y << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
