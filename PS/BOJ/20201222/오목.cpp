#include <iostream>

using namespace std;

const int MAX = 19;

int board[MAX][MAX];	// 1: black, 2: white

bool go(int x, int y, int dol) {
	int cnt;
	
	// horizontal
	cnt = 1;
	int L = y - 1, R = y + 1;
	while(L >= 1 && board[x][L] == dol) cnt++, L--;
	while(R <= MAX && board[x][R] == dol) cnt++, R++;
	if(cnt == 5) return true;
	
	// vertical
	cnt = 1;
	int U = x - 1, D = x + 1;
	while(U >= 1 && board[U][y] == dol) cnt++, U--;
	while(D <= MAX && board[D][y] == dol) cnt++, D++;
	if(cnt == 5) return true;
	
	// diagonal left to right
	cnt = 1;
	L = y - 1, R = y + 1, U = x - 1, D = x + 1;
	while(U >= 1 && L >= 1 && board[U][L] == dol) cnt++, U--, L--;
	while(D <= MAX && R <= MAX && board[D][R] == dol) cnt++, D++, R++;
	if(cnt == 5) return true;
	
	// diagonal right to left
	cnt = 1;
	L = y - 1, R = y + 1, U = x - 1, D = x + 1;
	while(U >= 1 && R <= MAX && board[U][R] == dol) cnt++, U--, R++;
	while(D <= MAX && L >= 1 && board[D][L] == dol) cnt++, D++, L--;
	if(cnt == 5) return true;
	
	return false;
}

int main() {
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		
		board[x][y] = (i % 2) + 1;
		
		if(go(x, y, board[x][y])) {
			cout << i << '\n';
			return 0;
		}
	}
	
	cout << -1 << '\n';

	return 0;
}
