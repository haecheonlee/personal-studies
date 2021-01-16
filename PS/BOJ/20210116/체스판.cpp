/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 4;
const int MAX_M = 47;
const int INF = 1e8;

int N, M;
char init[MAX_N][MAX_M];
char board[MAX_M][MAX_N];
int d[MAX_N * MAX_M][1 << 4];

int go(int p, int state) {
	if(p == N * M) return (state == 0 ? 0 : -INF);
	if(p > N * M) return -INF;
	
	int& ret = d[p][state];
	if(ret != -1) return ret;
	
	int i = p / M, j = p % M;
	if(board[i][j] == 'X') return ret = go(p + 1, state >> 1);

	// skip
	ret = go(p + 1, state >> 1);
	
	if((state & 1) == 0) {
		if((i + j) % 2 == 0) {
			// BLACK 
			
			// BW
			// W.
			if(i + 1 < N && j + 1 < M) {
				if((state & 2) == 0 && board[i][j + 1] == '.' && board[i + 1][j] == '.') {
					ret = max(ret, go(p + 2, (state >> 2) | (1 << (M - 2))) + 1);
				}
			}
		} else {
			// WHITE
			
			// WB
			// .W
			if(i + 1 < N && j + 1 < M) {
				if((state & 2) == 0 && board[i][j + 1] == '.' && board[i + 1][j + 1] == '.') {
					ret = max(ret, go(p + 2, (state >> 2) | (1 << (M - 1))) + 1);
				}
			}
			
			// .W
			// WB
			if(i + 1 < N && j - 1 >= 0) {
				if((state & (1 << (M - 1))) == 0 && board[i + 1][j - 1] == '.' && board[i + 1][j] == '.') {
					ret = max(ret, go(p + 1, (state >> 1) | (1 << (M - 1)) | (1 << (M - 2))) + 1);
				}
			}
			
			// W.
			// BW
			if(i + 1 < N && j + 1 < M) {
				if(board[i + 1][j] == '.' && board[i + 1][j + 1] == '.') {
					ret = max(ret, go(p + 2, (state >> 2) | (1 << (M - 1)) | (1 << (M - 2))) + 1);
				}
			}
		}
	}
	
	return ret;
}

int main() {
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++)
			cin >> init[i][j];
			
	for(int j = 0; j < M; j++) 
		for(int i = 0; i < N; i++) 
			board[j][i] = init[i][j];
	
	swap(N, M);
	memset(d, -1, sizeof(d));
	cout << go(0, 0) << '\n';
	

	return 0;
}
