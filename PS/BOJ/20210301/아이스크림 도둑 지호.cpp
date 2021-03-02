#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)(x.size())
using namespace std;

const int MAX_N = 1e5 + 2;

set<int> a;
map<int,int> p;
vector<int> G[MAX_N];
int key = 1;

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		a.insert(x);
		if(p.find(x) == p.end()) p[x] = key++;
		G[p[x]].push_back(i);
	}
	
	for(int i = 1; i < key; i++) sort(G[i].begin(), G[i].end());

	int cnt = 0;
	bool forward = true;
	for(auto it = a.rbegin(); it != a.rend(); it++) {
		int now = p[*it];
		int L = 0, R = sz(G[now]) - 1;
		
		while(L <= R) {
			if(cnt == M) return 0;
			if(forward) cout << G[now][L++] << '\n';
			else cout << G[now][R--] << '\n';
			
			if(*it % 7 == 0) forward = !forward;
			cnt++;
		}
	}

	return 0;
}
