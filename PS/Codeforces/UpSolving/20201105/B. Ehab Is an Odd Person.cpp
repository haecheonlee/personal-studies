/* reference: editorial */

#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int N;
	cin >> N;
	
	int a[N];
	bool p[2];
	for(int i = 0; i <N ; i++) {
		cin >> a[i];
		p[a[i] % 2] = true;	
	}
	
	if(p[0] && p[1]) sort(a, a + N);
	for(int i = 0; i < N; i++) cout << a[i] <<' ';

	return 0;
}
