#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	string a, b; cin >> a >> b;

	long long o1 = 0, o2 = 0, z1 = 0, z2 = 0;
	for(int i = 0; i < N; i++) {
		if(b[i] == '1') {
			if(a[i] == '1') o1++; else z1++;
		} else {
			if(a[i] == '1') o2++; else z2++;
		}
	}
	cout << o1 * z2 + o2 * z1 + o2 * z2 << '\n';
	
	return 0;
}
