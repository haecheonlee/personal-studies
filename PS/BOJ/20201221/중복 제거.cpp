/* reference: https://jaimemin.tistory.com/498 */

#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int arr[(1 << 25) / 32];

int main() {
    fastio
    
	int N;
	while(cin >> N) {
		int quotient = N / 32;
		int remainder = (1 << (N % 32));
		
		if(!(arr[quotient] & remainder)) {
			arr[quotient] += remainder;
			cout << N << ' ';
		}
	}

	return 0;
}
