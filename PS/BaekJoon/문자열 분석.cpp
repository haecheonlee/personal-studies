#include <iostream>

using namespace std;

int main() {
	string s;

	while(getline(cin, s)) {
		int c1=0,c2=0,c3=0,c4=0;
		for(int i=0; i<s.size(); i++) {
			if(s[i]>='a' && s[i]<='z') c1++;
			if(s[i]>='A' && s[i]<='Z') c2++;
			if(s[i]>='0' && s[i]<='9') c3++;
			if(s[i]==' ') c4++;
		}
		
		cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<endl;
	}
	return 0;
}

/*
boj.kr/10820

INPUT:
This is String
SPACE    1    SPACE
 S a M p L e I n P u T     
0L1A2S3T4L5I6N7E8

OUTPUT:
10 2 0 2
0 10 1 8
5 6 0 16
0 8 9 0
*/
