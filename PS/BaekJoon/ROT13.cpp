#include <iostream>

using namespace std;

char transform(char c) {
	if(c>='A' && c<='Z') {
		if(c+13>'Z') return 'A'+((c+12)-'Z');
	} else {
		if(c+13>'z') return 'a'+((c+12)-'z');
	}
	
	return c+13;
}

int main() {
	string s;
	getline(cin,s);
	
	for(int i=0; i<s.size(); i++) {
		char c=s[i];
		if((c>='A' && c<='Z') || (c>='a' && c<='z')){
			cout<<transform(c);
		} else {
			cout<<c;
		}
	}

	return 0;
}

/*
boj.kr/11655

INPUT:
Baekjoon Online Judge

OUTPUT:
Onrxwbba Bayvar Whqtr
*/
