#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	string s = "*";
	for(int i=0; i<N; i++) {
		for(int j=0; j<N-i-1; j++) cout<<" ";
		cout<<s<<endl;
		s += "**";
	}

	return 0;
}

/*

boj.kr/2442

INPUT:
5

OUTPUT:
    *
   ***
  *****
 *******
*********

*/
