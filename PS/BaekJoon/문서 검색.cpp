#include <iostream>

using namespace std;

int main() {
	string s, word;
	getline(cin,s);
	cin>>word;
	
	int cnt=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]==word[0]) {
			string extract=s.substr(i,word.size());
			if(extract==word) {
				cnt++;
				i+=word.size()-1;
			}
		}
	}
	
	cout<<cnt;
	
	return 0;
}

/*
boj.kr/1543

INPUT:
ababababa
aba

OUTPUT:
2
*/
