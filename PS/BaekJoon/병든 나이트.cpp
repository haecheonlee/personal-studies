// reference: baekjoon/codeplus

#include <iostream>

using namespace std;

int main() {
	int H,W;
	cin>>H>>W;

	if(H==1) {
		cout<<1;
	} else if(H==2) {
		cout<<min(4, (W+1)/2);
	} else if(H>=3) {
		if(W>=7) cout<<W-2;
		else cout<<min(4, W);
	}

	return 0;
}
