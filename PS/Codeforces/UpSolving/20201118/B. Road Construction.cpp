#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

bool check[MAX];

int main() {
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		check[u] = check[v] = true;
	}

	int K = -1;
	for(int i = 1; i <= N; i++) {
		if(check[i] == false) K = i;
	}

	vector<pii> ans;
	for(int i = 1; i <= N; i++) {
		if(i == K) continue;
		ans.push_back({i, K});
	}
	
	cout << ans.size() << '\n';
	for(auto& p : ans) cout << p.first << ' ' << p.second << '\n';
	
	return 0;
}
