#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	
	int skip = -1;
	for(int i = 0; i < N - 1; i++) {
		if(s[i] > s[i + 1]) {
			skip = i;
			break;
		}
	}
	
	if(skip == -1) skip = N - 1;
	for(int i = 0; i < N; i++) {
		if(i == skip) continue;
		cout << s[i];
	}

	return 0;
}
