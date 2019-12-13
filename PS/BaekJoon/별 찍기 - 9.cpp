#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;

	string s = "";
	int length = N*2;

	for(int i=0; i<length-1; i++) s += "*";
	
	for(int i=0; i<length-1; i++) {
		if(i < length / 2) {
			for(int j=0; j<i; j++) cout<<" ";
			cout<<s<<endl;
			
			if(i + 1 != length/2) s.erase(0, 2);
		} else {
			s += "**";
			for(int j=length-i-2; j>0; j--) cout<<" ";
			
			cout<<s<<endl;
		}
	}

	return 0;
}

/*

boj.kr/2446

INPUT:
5

OUTPUT:
*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********

*/
