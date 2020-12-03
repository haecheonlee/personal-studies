#include <iostream>

using namespace std;

const int MAX = 10;

int a[MAX];

int go(int n, int p, int pp, int solved) {
	if(n >= MAX) return (solved >= 5);
	int ret = 0;
	
	for(int i = 1; i <= 5; i++) {
		if(i == p && p == pp) continue;
		ret += go(n + 1, i, p, solved + (a[n] == i));
	}
	
	return ret;
}

int main() {
	for(int i = 0; i < MAX; i++) cin >> a[i];
	
	cout << go(0, 0, 0, 0);
	
	return 0;
}
