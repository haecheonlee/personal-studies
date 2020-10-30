#include <iostream>

using namespace std;

int go(int a, int b) {
	if(a > b) return 1e4;
	if(a == b) return 0;
	
	return min(go(a + 1, b) + 1, go(a * 2, b + 3) + 1);
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int a,b;
		cin>>a>>b;
		
		cout<<go(a,b)<<'\n';
	}
	
	return 0;
}
