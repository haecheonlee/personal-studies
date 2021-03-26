#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	int a[7];
	for(int i = 0; i < 7; i++) cin >> a[i];
	
	int sum = 0;
	while(1) {
		for(int i = 0; i < 7; i++) {
			sum += a[i];
			if(sum >= N) {
				cout << i + 1 << '\n';
				return 0;
			}
		}
	}
	
	return 0;
}
