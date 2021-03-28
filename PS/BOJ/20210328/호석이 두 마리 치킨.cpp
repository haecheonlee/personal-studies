#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 1e2 + 10;

int N, M;
vector<int> G[MAX_N];
int d[MAX_N];

int bfs(int s1, int s2) {
	 memset(d, -1, sizeof(d));
	 queue<int> q;
	 q.push(s1); q.push(s2);
	 d[s1] = d[s2] = 0;
	 
	 while(!q.empty()) {
	 	int x = q.front();
	 	q.pop();
	 	
	 	for(auto& y : G[x]) {
	 		if(d[y] == -1) {
	 			d[y] = d[x] + 2;
	 			q.push(y);
	 		}
	 	}
	 }
	 
	 int dist = 0;
	 for(int i = 1; i <= N; i++) dist += d[i];
	 
	 return dist;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		
		G[x].push_back(y);
		G[y].push_back(x);
	}

	int s1 = -1, s2 = -1, ans = 1e9;
	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) {
			int dist = bfs(i,j);
			if(ans > dist) s1 = i, s2 = j, ans = dist;
		}
	}
	cout << s1 << ' ' << s2 << ' ' << ans << '\n';

	return 0;
}
