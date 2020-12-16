/* reference: PS Open tack/ weasell */

#include <iostream>

using namespace std;

const int MAX = 3e3;

int N;
int a[MAX];
int sum;

bool chk(int x) {
	if(sum % x != 0) return false;
	
	int g = sum / x, tmp = 0;
	for(int i = 0; i < N; i++) {
		tmp += a[i];
		
		if(tmp > g) return false;
		if(tmp == g) {
			tmp = 0;
			x--;
		}
	}
	
	return x == 0;
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		cin >> N;
		
		sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> a[i];
			sum += a[i];
		}
		
		for(int i = N; i >= 1; i--) {
			if(chk(i)) {
				cout << N - i << '\n';
				break;
			}
		}
	}
	
	return 0;
}
