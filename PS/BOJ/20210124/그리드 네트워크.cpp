#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 500 * 500 + 10;

int p[MAX];

int Find(int x) {
	return (p[x] == x ? x : p[x] = Find(p[x]));
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) p[x] = y;
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int N, M;
		cin >> N >> M;
		
		vector<pair<int, pii>> G;
		
		for(int i = 1; i <= N * M; i++) p[i] = i;
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M - 1; j++) {
				int cost;
				cin >> cost;
				
				int x = i * M + j + 1;
				int y = i * M + j + 2;
				
				G.push_back({cost, {x, y}});
			}
		}

		for(int i = 0; i < N - 1; i++) {
			for(int j = 0; j < M; j++) {
				int cost;
				cin >> cost;
				
				int x = i * M + j + 1;
				int y = i * M + j + M + 1;
				
				G.push_back({cost, {x, y}});
			}
		}
		
		sort(G.begin(), G.end());
		
		int ans = 0;
		for(int i = 0; i < (int)G.size(); i++) {
			int cost = G[i].first;
			int x = G[i].second.first;
			int y = G[i].second.second;
			
			if(Find(x) != Find(y)) {
				Union(x, y);
				ans += cost;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
