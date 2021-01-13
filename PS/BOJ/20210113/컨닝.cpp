/* reference: backejoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10;

int N, M;
char board[MAX][MAX];
int d[MAX][(1 << MAX)];

bool isset(int state, int i) {
	return (state & (1 << i));
}

bool check(int row, int state) {
	if(row < 0) return true;
	
	// 현재 위치에서, j와 j +  1, 사람이 붙어서 앉아있는지 확인함
	for(int j = 0; j < M - 1; j++) {
		if(isset(state, j) && isset(state, j + 1)) 
			return false;
	}
	
	// 현재 위치에서, 'x', 앉을수 없는 위치에 사람이 있는지 확인함
	for(int j = 0; j < M; j++) {
		if(board[row][j] == 'x' && isset(state, j)) 
			return false;
	}
	
	return true;
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		cin >> N >> M;
		
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < M; j++) cin >> board[i][j];
		
		memset(d, 0, sizeof(d));
		for(int row = 0; row < N; row++) {
			for(int state = 0; state < (1 << M); state++) {
				if(!check(row, state)) continue;
				
				// 현재 위치(row)의 상태는 state
				// 아래 위치(row - 1)의 상태는 pstate
				
				for(int pstate = 0; pstate < (1 << M); pstate++) {
					if(!check(row - 1, pstate)) continue;
					
					int cnt = 0;
					bool is_good = 1;
					
					for(int j = 0; j < M; j++) {
						if(isset(state, j)) {
							cnt += 1;
							
							// 현재 위치 j에 앉을때, 
							// 대각선 왼쪽 아래 / 오른 쪽 아래에 사람 있는지 체크 함
							if(j - 1 >= 0 && isset(pstate, j - 1)) is_good = false;
							if(j + 1 < M && isset(pstate, j + 1)) is_good = false;
						}
					}
					
					if(is_good) {
						if(row == 0) d[row][state] = max(d[row][state], cnt);
						else d[row][state] = max(d[row][state], d[row - 1][pstate] + cnt); 
					}
				}
			}
		}
		
		int ans = 0;
		for(int state = 0; state < (1 << M); state++) ans = max(ans, d[N - 1][state]);
		cout << ans << '\n';
	}
	
	return 0;
}
