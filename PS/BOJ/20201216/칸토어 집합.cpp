#include <iostream>
#include <cmath>

using namespace std;

void go(int n) {
	if(n == 1) {
		cout << '-';
		return;
	}
	
	go(n / 3);
	for(int i = 0; i < n / 3; i++) cout << ' ';
	go(n / 3);
}

int main() {
	int N;
	while(cin >> N) { go(pow(3, N)); cout << '\n'; }
	
	return 0;
}
