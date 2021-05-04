#include <iostream>

using namespace std;

int a[] = { 1234567, 123456, 1234 };

int main() {
	int N; cin >> N;
	
	for(int i = 0; i <= N / a[0]; i++) {
		for(int j = 0; a[0] * i + a[1] * j <= N; j++) {
			int sum = a[0] * i + a[1] * j;
			if((N - sum) % a[2] == 0) {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}
	cout << "NO" << '\n';

	return 0;
}
