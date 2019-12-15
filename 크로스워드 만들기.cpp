#include <iostream>

using namespace std;

int main() {
	string A, B;
	cin>>A>>B;
	
	string result[B.size()][A.size()];
	
	int found, index;
	for(int i=0; i<A.size(); i++) {
		found = B.find(A[i]);
		if(found != string::npos) { 
			index = i;
			break;
		}
	}
	
	for(int i=0; i<B.size(); i++) {
		for(int j=0; j<A.size(); j++) {
			if(j == index) cout<<B[i]; 
			else if(found == i) cout<<A[j];
			else cout<<".";
		}
		cout<<endl;
	}

	return 0;
}

/*
boj.kr/2804

INPUT:
BANANA PIDZAMA

OUTPUT:
.P....
.I....
.D....
.Z....
BANANA
.M....
.A....
*/
