#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		string a, b;
		cin >> a >> b;
		
		int aa = 0, bb = 0;
		for(int i = 0; i < (int)a.size(); i++) {
			if(a[i] != b[i]) {
				if(a[i] == '1') aa++;
				if(b[i] == '1') bb++;
			}
		}
		cout << max(aa, bb) << '\n';
	}
	
	return 0;
}
