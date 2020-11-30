#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 6;

int N;
char a[MAX][MAX];
int d[MAX][MAX];

bool chk(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

int calc(int fi, int sc, char opr) {
	if(opr == '+') return fi + sc;
	if(opr == '-') return fi - sc;
	if(opr == '*') return fi * sc;

	return 0;	
}

int main() {
	cin >> N;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) cin >> a[i][j];
	}
	
	memset(d, -0x3f, sizeof(d));
	d[1][1] = a[1][1] - '0';
	for(int i = 1; i <= N; i++) {
		int ii = i + 1;
		for(int j = 1; j <= N; j++) {
			int jj = j + 1;

			if(a[i][j] >= '0' && a[i][j] <= '9') {

				if(chk(ii, j)) d[ii][j] = max(d[ii][j], d[i][j]);
				if(chk(i, jj)) d[i][jj] = max(d[i][jj], d[i][j]);
			} else {
				if(chk(ii, j)) d[ii][j] = max(d[ii][j], calc(d[i][j], a[ii][j] - '0', a[i][j]));
				if(chk(i, jj)) d[i][jj] = max(d[i][jj], calc(d[i][j], a[i][jj] - '0', a[i][j]));
			}
		}
	}
	
	// print max value
	cout << d[N][N] << ' ';
	
	memset(d, 0x3f, sizeof(d));
	d[1][1] = a[1][1] - '0';
	for(int i = 1; i <= N; i++) {
		int ii = i + 1;
		for(int j = 1; j <= N; j++) {
			int jj = j + 1;

			if(a[i][j] >= '0' && a[i][j] <= '9') {
				if(chk(ii, j)) d[ii][j] = min(d[ii][j], d[i][j]);
				if(chk(i, jj)) d[i][jj] = min(d[i][jj], d[i][j]);
			} else {
				if(chk(ii, j)) d[ii][j] = min(d[ii][j], calc(d[i][j], a[ii][j] - '0', a[i][j]));
				if(chk(i, jj)) d[i][jj] = min(d[i][jj], calc(d[i][j], a[i][jj] - '0', a[i][j]));
			}
		}
	}
	cout << d[N][N];
	
	return 0;
}
