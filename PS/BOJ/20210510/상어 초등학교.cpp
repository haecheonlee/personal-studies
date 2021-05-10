#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 22;

int N, NN;
int a[MAX_N][MAX_N];
vector<int> fav[MAX_N * MAX_N];
int dx[] = {0, 0, 1, -1, 0};
int dy[] = {-1, 1, 0, 0, 0};

bool is_ranged(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

int convertToIndex(const int& x, const int& y) {
	int py = y % N; if(py == 0) py = N;
	return N * (x - 1) + py;
}

int calc(vector<int>& p, const int& x, const int& y, int& left) {
	int cnt = 0;
	
	for(int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		
		if(is_ranged(nx, ny)) {
			left += (a[nx][ny] == 0);
			for(auto& pp : p) {
				if(pp == a[nx][ny]) {
					cnt++;
					break;
				}
			}
		}
	}
	
	return cnt;
}

int find(vector<int>& p) {
	int pos = NN + 1, cntFav = -1, cntLeft = -1;
	
	for(int now = 1; now <= NN; now++) {
		int x = now / N + 1;
		int y = now % N; if(y == 0) y = N, x--;
		if(a[x][y]) continue;
		
		if(1 <= x && x <= NN && 1 <= y && y <= NN) {
			int left = 0;
			int fav = calc(p, x, y, left);
			int selectedPos = convertToIndex(x, y);

			if(fav > cntFav) {
				// condition 1: more number of fav cell
				pos = selectedPos;
				cntFav = fav;
				cntLeft = left;
			} else if(fav == cntFav) {
				// condition 2: more number of left cell
				if(left > cntLeft) {
					pos = selectedPos;
					cntLeft = left;
				} else if(left == cntLeft) {
					// condition 3: smaller index
					if(pos > selectedPos) pos = selectedPos;
				}
			}
		}
	}
	
	return pos;
}

int main() {
	cin >> N;
	NN = N * N;
	
	for(int i = 1; i <= NN; i++) {
		int x; cin >> x;
		
		fav[x].resize(4);
		for(auto& k : fav[x]) cin >> k;
		
		int idx = find(fav[x]);
		int px = idx / N + 1, py = idx % N;
		if(py == 0) px--, py = N;
		a[px][py] = x;
	}

	int ans = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			int cnt = 0;
			for(int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if(is_ranged(nx, ny)) for(auto& f : fav[a[i][j]]) cnt += (f == a[nx][ny]);
			}

			if(cnt == 1) ans += 1;
			else if(cnt == 2) ans += 10;
			else if(cnt == 3) ans += 100;
			else if(cnt == 4) ans += 1000;
		}
	}
	cout << ans << '\n';

	return 0;
}
