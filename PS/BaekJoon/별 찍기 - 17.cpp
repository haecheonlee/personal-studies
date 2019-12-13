#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	string pad = " ";
	for(int i=0; i<N; i++) {
		for(int j=i; j<N-1; j++) cout<<" ";	
		
		if(i == 0 || i == N-1) {
			// first & last
			for(int j=0; j<=i*2; j++) {
				cout<<"*";
			}
			cout<<endl;
		} else {
			cout<<"*";
			cout<<pad;
			pad += "  ";
			cout<<"*";
			cout<<endl;
		}
	}
	
	return 0;
}
/*
boj.kr/10992

INPUT:
4

OUTPUT:
   *
  * *
 *   *
*******
*/
