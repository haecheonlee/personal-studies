#include <iostream>

using namespace std;

const int MAX = 25;

int N, ans;
int a[MAX];

void go(int n, int sum) {
	if(n >= N) {
		if(sum == (1 << 26) - 1) ans++;
		return;
	}
	
	// skip 
	go(n + 1, sum);
	
	// take
	go(n + 1, sum | a[n]);
}

int main() {
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		
		int sum = 0;
		for(auto& c : s) sum |= (1 << (c - 'a'));
		a[i] = sum;
	}
	
	go(0, 0);
	cout << ans << '\n';
	
	return 0;
}
