#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		string s1,s2;
		
		cin>>s1>>s2;
		
		int cnt=0;
		for(int i=0; i<s1.size(); i++) {
			if(s1[i]!=s2[i]) cnt++;
		}
		cout<<"Hamming distance is "<<cnt<<".\n";
	}

	return 0;
}

/*
INPUT:
4
0
1
000
000
1111111100000000
0000000011111111
101
000

OUTPUT:
Hamming distance is 1.
Hamming distance is 0.
Hamming distance is 16.
Hamming distance is 2.
*/
