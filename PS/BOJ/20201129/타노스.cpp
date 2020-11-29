#include <iostream>

using namespace std;

const int MAX = 5e2;

bool check[MAX];

int main() {
	string s;
	cin >> s;
	
	int a = 0, b = 0;
	for(auto& c : s) if(c == '0') a++; else b++;
	
	a /= 2;
	b /= 2;
	
	int L = (int)s.size() - 1;
	for(int i = L; i >= 0 && a; i--) {
		if(s[i] == '0') a--, check[i] = 1;
	}
	for(int i = 0; i <= L && b; i++) {
		if(s[i] == '1') b--, check[i] = 1; 
	}

	for(int i = 0; i <= L; i++) {
		if(!check[i]) cout << s[i];
	}
	
	return 0;
}
