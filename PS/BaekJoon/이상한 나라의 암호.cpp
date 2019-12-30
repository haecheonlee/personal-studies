#include <iostream>

using namespace std;

int main() {
	string s;
	
	int count=1;
	while(1) {
		getline(cin, s);
		if(s == "Was it a cat I saw?") break;
		
		for(int i=0; i<s.size(); i+=(count+1)) {
			cout<<s[i];
		}
		count++;
		cout<<endl;
	}
	
	return 0;
}

/*
boj.kr/18245

INPUT:
RAEBDCVDEELFVGEHT
SIJEKLUMNLOPGQRI
ISTURVWXEYZANBCDE
WEFGHEIJKLNMNOPDQRSTY
YUVWXYEZABCDREFGHII
JJKLMNOOPQRSTUY
Was it a cat I saw?

OUTPUT:
REDVELVET
SEULGI
IRENE
WENDY
YERI
JOY
*/
