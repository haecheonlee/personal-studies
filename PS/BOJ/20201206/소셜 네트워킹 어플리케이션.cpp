#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

const int MAX = 1e6 + 1;

int p[MAX];

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
	fastio
	
	int T;
	cin >> T;
	
	for(int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;
		
		for(int i = 0; i < N; i++) p[i] = i;
		
		for(int i = 0; i < K; i++) {
			int u, v;
			cin >> u >> v;
			
			Union(u, v);
		}
		
		int M;
		cin >> M;
		
		cout << "Scenario " << tc << ":\n";
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			
			if(Find(u) == Find(v)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		cout << '\n';
	}
	
	return 0;
}
