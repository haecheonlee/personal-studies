#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int N, M, R, C;
		cin >> N >> M >> R >> C;
		
		int lt = abs(R - 1) + abs(C - 1);
		int rt = abs(R - 1) + abs(C - M);
		int lb = abs(R - N) + abs(C - 1);
		int rb = abs(R - N) + abs(C - M);
		
		cout << max (max(lt, rt), max(lb, rb)) << '\n';
	}

	return 0;
}
