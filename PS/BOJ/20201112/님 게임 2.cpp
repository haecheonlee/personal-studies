#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		ans ^= x;
	}
	
	cout << ((ans) ? "koosaga" : "cubelover");

	return 0;
}
