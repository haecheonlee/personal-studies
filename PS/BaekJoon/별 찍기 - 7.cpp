#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	string str="*";
	for(int i=0; i<N; i++) {
		for(int j=0; j<N-i-1; j++) cout<<" ";
		cout<<str<<endl;
		if(i<N-1) str+="**";
	}
	
	for(int i=N-1; i>0; i--) {
		for(int j=i; j<N; j++) cout<<" ";
		if(str.size()>2) str.erase(0,2);
		cout<<str<<endl;
	}

	return 0;
}

/*
boj.kr/2444

INPUT:
5

OUTPUT:
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/
