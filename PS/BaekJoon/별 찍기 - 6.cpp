#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	for(int i=N; i>0; i--) {
		for(int j=i; j<N; j++) cout<<" ";
		for(int j=0; j<i*2-1; j++) cout<<"*";
		cout<<endl;
	}

	return 0;
}

/*
boj.kr/2443

INPUT:
5

OUTPUT:
*********
 *******
  *****
   ***
    *
*/
