/* reference: http://blog.naver.com/jinhan814/222157895340 */

#include <iostream>
#include <vector>
#include <algorithm>

#define sz(x) (int)(x.size())

using namespace std;

typedef pair<int,int> pii;

struct Info {
	int x, y, fuel;
	bool operator < (const Info& i) const {
		return x + y < i.x + i.y;
	}
};

int N, M, K;
vector<Info> G;

bool g(const Info& u, const Info& v) {
	return (u.x <= v.x && u.y <= v.y);
}

int f(const Info& u, const Info& v) {
	return abs(u.x - v.x) + abs(u.y - v.y);
}

bool chk(int k) {
	vector<int> dp(sz(G), -1);
	dp[0] = k;
	
	for(int i = 1; i < sz(G); i++) {
		for(int j = 0; j < i; j++) {
			if(!g(G[j], G[i])) continue;
			if(dp[j] < f(G[j], G[i])) continue;
			
			dp[i] = max(dp[i], dp[j] - f(G[j], G[i]) + G[i].fuel);
		}
	}
	
	return dp.back() != -1;
}

int main() {
	cin >> N >> M >> K;
	
	for(int i = 0; i < K; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G.push_back({u, v, c});
	}
	G.push_back({1, 1, 0});
	G.push_back({N, M, 0});
	
	sort(G.begin(), G.end());
	
	int ans = 1e9;
	int L = 0, R = 1e9;
	while(L <= R) {
		int MID = (L + R) / 2;
		if(chk(MID)) ans = MID, R = MID - 1;
		else L = MID + 1;
	}
	cout << ans << '\n';
	
	return 0;
} 
