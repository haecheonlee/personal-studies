#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	
	int f = 0, z = 0;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		
		if(x == 5) f++;
		else z++;
	}

	f = (f / 9) * 9;

	if(f && z) {
		for(int i = 1; i <= f; i++) cout << 5;
		for(int i = 1; i <= z; i++) cout << 0;
	} else if(z){
		cout << 0 << '\n';
	} else {
		cout << -1 << '\n';
	}
	
	return 0;
}
