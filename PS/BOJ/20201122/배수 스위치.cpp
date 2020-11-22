#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	int ans = 0;
	int N = (int)(s.size());
	for(int i = 0; i < N; i++) {
		if(s[i] == 'Y') {
			int k = i + 1;
			for(int j = i; j < N; j += k) {
				if(s[j] == 'N') s[j] = 'Y';
				else s[j] = 'N';
			}

			ans++;
		}
	}
	
	cout << (N < ans ? -1 : ans); 
	
	return 0;
}
