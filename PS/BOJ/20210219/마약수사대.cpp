#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[26];
int in[26];
bool check[26], caught[26];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < M; i++) {
		char a, b; cin >> a >> b;
		
		int u = a - 'A', v = b - 'A';
		G[u].push_back(v);
		in[v]++;
	}

	int K; cin >> K;
	for(int i = 0; i < K; i++) {
		char x; cin >> x;
		caught[x - 'A'] = 1;
	}

	int init = 0;
	queue<int> q;
	for(int i = 0; i < N; i++) {
		if(in[i] == 0 && !caught[i]) {
			init++;
			check[i] = 1;
			q.push(i);
		}
	}
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();

		for(auto& y : G[x]) {
			if(caught[y]) continue;
			if(!check[y]) {
				check[y] = 1;
				q.push(y);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++) ans += check[i];
	cout << ans - init  << '\n';
	
	return 0;
}
