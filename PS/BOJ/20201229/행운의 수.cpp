#include <iostream>
#include <set>

using namespace std;

const int MAX = 50;

int a[MAX], b[MAX], c[MAX];

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int a_N, b_N, c_N;
		
		cin >> a_N;
		for(int i = 0; i < a_N; i++) cin >> a[i];
		
		cin >> b_N;
		for(int i = 0; i < b_N; i++) cin >> b[i];
		
		cin >> c_N;
		for(int i = 0; i < c_N; i++) cin >> c[i];
		
		set<int> ans;
		for(int aa = 0; aa < a_N; aa++) {
			for(int bb = 0; bb < b_N; bb++) {
				for(int cc = 0; cc < c_N; cc++) {
					int sum = a[aa] + b[bb] + c[cc];
					int total = sum;
					
					bool is_good = true;
					while(sum && is_good) {
						int digit = sum % 10;
						sum /= 10;
						if(digit != 5 && digit != 8) is_good = false; 
					}

					if(is_good) ans.insert(total);

				}
			}
		}
		cout << (int)ans.size() << '\n';
	}

	return 0;
}
