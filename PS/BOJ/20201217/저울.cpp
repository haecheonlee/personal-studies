/* reference: https://jaimemin.tistory.com/756 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	if(a[0] != 1) {
		cout << 1 << '\n';
	} else {
		int sum = 1;
		for(int i = 1; i < N; i++) {
			if(a[i] > sum + 1) break;
			sum += a[i];
		}
		cout << sum + 1 << '\n';
	}
	
	return 0;
}
