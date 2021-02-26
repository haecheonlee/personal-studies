#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;

	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int turn = 1, A = 0, B = 0;
	int L = 1, R = N;
	while(L <= R) {
		if(turn & 1) {
			// first
			if(a[L] < a[R]) A += a[R], R--;
			else A += a[L], L++;
		} else {
			// second
			if(a[L] < a[R]) B += a[R], R--;
			else B += a[L], L++;
		}
		
		turn++;
	}
	
	cout << A << ' ' << B << '\n';
	
	return 0;
}
