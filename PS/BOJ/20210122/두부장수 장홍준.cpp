/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 14;
const int INF = 1e9;

int N, M;
char board[MAX][MAX];
int d[MAX * MAX][1 << 14];
int scores[][6] = {
	{10, 8, 7, 5, 0, 1},
	{8, 6, 4, 3, 0, 1},
	{7, 4, 3, 2, 0, 1},
	{5, 3, 2, 2, 0, 1},
	{0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 0, 0}
};

int calc(char x, char y) {
	return scores[x - 'A'][y - 'A'];
}

int go(int p, int state) {
	if(p >= N * M) return 0;
	
	int& ret = d[p][state];
	if(ret != -1) return ret;
	ret = 0;
	
	int i = p / M, j = p % M;

	// skip
	ret = max(ret, go(p + 1, (state >> 1)));
	
	if((state & 1) == 0) {
		if(j != M - 1 && ((state & 2) == 0)) {
			int score = calc(board[i][j], board[i][j + 1]);
			
			int tmp = go(p + 2, (state >> 2)) + score;
 			ret = max(ret, tmp);
		}
		
		if(i != N - 1) {
			int score = calc(board[i][j], board[i + 1][j]);
			
			int tmp = go(p + 1, (state >> 1) | (1 << (M - 1))) + score;
			ret = max(ret, tmp);
		}
	}
	
	return ret;
}

int main() {
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++)
			cin >> board[i][j];
	
	memset(d, -1, sizeof(d));
	cout << go(0, 0) << '\n';

	return 0;
}
