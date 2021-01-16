/* reference: beakjoon/codeplus */

#include <iostream>
#include <vector>
/* reference: beakjoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e8;

int N, M;
int d[10 * 25][1 << 10];
char board[25][25];

int go(int p, int state) {
	if(p == N * M) return (state == 0 ? 0 : -INF);
	if(p > N * M) return -INF;
	
	int& ret = d[p][state];
	if(ret != -1) return ret;
	
	int i = p / M, j = p % M;
	// if current position's board is '1'
	if(board[i][j] == '1') return ret = go(p + 1, state >> 1) + 1;
	
	// skip
	ret = go(p + 1, state >> 1);
	
	// use block-1
	if((state & 1) == 0) ret = max(ret, go(p + 1, state >> 1) + 1);
	
	// use block-4
	if(i != N - 1 && j != M - 1 && (state & 1) == 0 && (state & 2) == 0) {
		if(board[i][j + 1] == '.' && board[i + 1][j] == '.' && board[i + 1][j + 1] == '.') {
			ret = max(ret, go(p + 2, (state >> 2) | (1 << (M - 1)) | (1 << (M - 2))) + 16);
		}
	}
	
	return ret;
}

int main() {
	cin >> N >> M;
	
	char init[25][25];
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++) 
			cin >> init[i][j];
		
	// [N][M] to [M][N]
	for(int j = 0; j < M; j++) 
		for(int i = 0; i < N; i++) 
			board[j][i] = init[i][j];
	
	swap(N, M);
	memset(d, -1, sizeof(d));
	cout << go(0, 0) << '\n';

	return 0;
}
