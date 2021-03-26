#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	N *= N;
	
	for(int i = 1; i <= N / 2; i++) 
		cout << i << ' ' << N - i + 1 << '\n';

	return 0;
}
