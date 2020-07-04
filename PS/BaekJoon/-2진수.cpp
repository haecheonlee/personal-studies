#include <iostream>

using namespace std;

void go(int n) {
	if(n==0) return;
	
	if(n%2==0) {
		go(-(n/2));
		cout<<0;
	} else {
		if(n>0) go(-(n/2));
		else go((-n+1)/2);
		cout<<1;
	}
}

int main() {
	int N;
	cin>>N;
	
	if(N==0) cout<<0;
	else go(N);

	return 0;
}
