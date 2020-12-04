#include <iostream>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int N;
		cin >> N;
		
		int mx = -1, idx = -1;
		int total = 0;
		bool duplicate = 0;
		for(int i = 1; i <= N; i++) {
			int x;
			cin >> x;
		
			total += x;
			if(x > mx) duplicate = 0, mx = x, idx = i;
			else if(x == mx) duplicate = 1;
		}
		
		if(duplicate == 1) {
			cout << "no winner\n";
		} else {
			cout << (mx <= (total / 2) ? "minority winner " : "majority winner ");
			cout << idx << '\n';
		}
	}

	return 0;
}
