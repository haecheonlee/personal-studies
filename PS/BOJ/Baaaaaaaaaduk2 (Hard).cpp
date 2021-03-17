#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second
#define sz(x) (int)x.size()

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

int N, M;
int a[MAX][MAX];
bool check[MAX][MAX];
vector<vector<pii>> G;
vector<vector<pii>> two_need, one_need, one_merged, two_merged;					// need to remove	(should be <= 2 for each)
vector<int> two_score, one_score, two_merged_score, one_merged_score;			// score for each group
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool chk(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

void bfs(int sx ,int sy) {
	vector<pii> g;
	queue<pii> q;
	q.push({sx, sy});
	check[sx][sy] = 1;
	g.push_back({sx, sy});
	
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().sc;
		q.pop();
		
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(chk(nx, ny) && !check[nx][ny] && a[nx][ny] == 2) {
				check[nx][ny] = 1;
				g.push_back({nx, ny});
				q.push({nx, ny});
			}
		}
	}
	
	G.push_back(g);
}

// find the adjacent 0s
void bfs2(int num) {
	vector<pii> found;
	for(auto& p : G[num]) {
		int x = p.fi, y = p.sc;
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(chk(nx, ny) && !check[nx][ny] && a[nx][ny] == 0) {
				check[nx][ny] = 1;
				found.push_back({nx, ny});
			}
		}
	}
	
	// reset the check array for other groups
	for(auto& p : found) check[p.fi][p.sc] = 0;
	
	if(sz(found) == 2) {
		two_need.push_back(found);
		two_score.push_back(sz(G[num]));
	} else if(sz(found) == 1) {
		one_need.push_back(found);
		one_score.push_back(sz(G[num]));
	}
}

int main() {
	fastio
	
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) 
			cin >> a[i][j];
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(!check[i][j] && a[i][j] == 2) 
				bfs(i, j);

	memset(check, 0, sizeof(check));
	for(int i = 0; i < sz(G); i++) bfs2(i);

	// merge into one as sharing the same 0 place
	bool one_check[sz(one_need)] { false };
	for(int i = 0; i < sz(one_need); i++) {
		if(one_check[i]) continue;
		one_check[i] = 1;
		
		int sum = one_score[i];
		int x = one_need[i][0].fi, y = one_need[i][0].sc;
		for(int j = i + 1; j < sz(one_need); j++) {
			if(one_check[j]) continue;
			int xx = one_need[j][0].fi, yy = one_need[j][0].sc;
			
			if(x == xx && y == yy) {
				one_check[j] = 1;
				sum += one_score[j];
			}
		}

		one_merged.push_back(one_need[i]);
		one_merged_score.push_back(sum);
	}
	
	bool two_check[sz(two_need)] { false };
	for(int i = 0; i < sz(two_need); i++) {
		if(two_check[i]) continue;
		two_check[i] = 1;
	
		int sum = two_score[i];
		for(int j = i + 1; j < sz(two_need); j++) {
			if(two_check[j]) continue;
			int same = 0;
			for(auto& p : two_need[i]) 
				for(auto& pp : two_need[j])
					if(p.fi == pp.fi && p.sc == pp.sc) 
						same++;
						
			if(same == 2) {
				two_check[j] = 1;
				sum += two_score[j];
			}
		}
		
		two_merged.push_back(two_need[i]);
		two_merged_score.push_back(sum);
	}
	
	int ans = 0;
	// 2 of one 
	for(int i = 0; i < sz(one_merged); i++) {
		ans = max(ans, one_merged_score[i]);
		for(int j = i + 1; j < sz(one_merged); j++) 
			ans = max(ans, one_merged_score[i] + one_merged_score[j]);
	}
	
	// 1 of two 
	for(int i = 0; i < sz(two_merged); i++)
		ans = max(ans, two_merged_score[i]);
	
	// 1 of two + (0 <= j <= 2) of one
	for(int i = 0; i < sz(two_merged); i++) {
		int sum  = two_merged_score[i];
		
		for(int j = 0; j < sz(one_merged); j++) {
			bool is_same = 0;
			for(auto& p : two_merged[i])
				if(p.fi == one_merged[j][0].fi && p.sc == one_merged[j][0].sc)
					is_same = 1;
			
			if(is_same) sum += one_merged_score[j];
		}
		ans = max(ans, sum);
	}

	cout << ans << '\n';

	return 0;
}
