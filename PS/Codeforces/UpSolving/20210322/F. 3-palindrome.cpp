#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	
	string s = "bba";
	for(int i = 3; i < N; i++) {
		char xx = s[i - 2], x = s[i - 1];
		char nx = (x == 'a' ? 'b' : 'a');
		
		if(xx == x) s += nx;
		else s += x;
	}

	for(int i = 0; i < N; i++) cout << s[i];

	return 0;
}
